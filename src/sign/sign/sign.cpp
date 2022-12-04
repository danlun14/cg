#include <sign.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/miller_rabin.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/integer/extended_euclidean.hpp>
#include <boost/multiprecision/integer.hpp>
#include <boost/integer/mod_inverse.hpp>

using namespace boost::multiprecision;
using namespace boost::random;
using boost::multiprecision::powm;

std::string readFile(const std::string &fileName)
{
    std::ifstream f(fileName);
    f.seekg(0, std::ios::end);
    size_t size = f.tellg();
    std::string s(size, ' ');
    f.seekg(0);
    f.read(&s[0], size);
    return s;
}

void fillFile(const std::string &fileName, std::string &data)
{
    std::ofstream f(fileName);
    f.write(data.c_str(), data.size());
}

long long hashFile(const std::string &filename, const long long del)
{
    std::string filedata = readFile(filename);

    std::string filehash = SHA256(filedata.c_str());
    // std::cout << filehash << '\n';
    filehash.erase(16, filehash.size() - 16);
    long long h = std::strtoll(filehash.c_str(), 0, 16);
    return h % del;
}

cpp_int hashFile(const std::string &filename, cpp_int del)
{
    std::string filedata = readFile(filename);

    std::string filehash = SHA256(filedata.c_str());

    cpp_int h;
    int startpos = 0;
    while (true)

    {
        h += strtoull(filehash.substr(startpos, 16).c_str(), 0, 16);
        startpos += 16;
        if (startpos == (256 / 4))
        {
            break;
        }
        h <<= 64;
    }
    return h % del;
}

namespace sign
{

    void RSA(const std::string &filename, long long &N, long long &d)
    {

        long long P = basic::simpleSafeNumber(20000);

        long long Q = basic::simpleSafeNumber(20000);
        std::cout << "P " << P << std::endl;
        std::cout << "Q " << Q << std::endl;

        N = 0;
        long long c = 0; // close
        d = 0;           // open

        cipher::init::RSA(P, Q, c, d, N);

        long long h = hashFile(filename, N);
        std::cout << "N " << N << std::endl;
        std::cout << "d " << d << std::endl;
        std::cout << "c " << c << std::endl;

        long long s = basic::powmod(h, c, N);

        std::cout << "s " << s << std::endl;
        std::stringstream outdata;
        outdata << s;
        std::string result;
        outdata >> result;
        fillFile("RSA.txt", result);

        std::cout << "h " << h << std::endl;
    }
    void elgamal(const std::string &filename, long long &P, long long &g, long long &y)
    {
        P = basic::simpleSafeNumber(20000);
        g = basic::getG(P);
        long long x = basic::simpleSafeNumber(P - 1);

        y = basic::powmod(g, x, P);

        long long h = hashFile(filename, P);
        long long k = basic::coPrime(P - 1, P - 1);
        long long r = basic::powmod(g, k, P);
        long long u = (h - x * r) % (P - 1);
        if (u < 0)
        {
            u += P - 1;
        }
        std::cout << u << '\n';
        long long s = (basic::reverse(P - 1, k) * u) % (P - 1);
        std::cout << "s - " << s << '\n';
        std::cout << "r - " << r << '\n';
        std::stringstream outdata;
        outdata << r;
        outdata << '\n';
        outdata << s;
        std::string result = outdata.str();
        fillFile("elgamal.txt", result);
    }

    cpp_int powM(cpp_int value, cpp_int exponent, cpp_int modulus)
    {
        value %= modulus;
        cpp_int result = 1;
        while (exponent > 0)
        {
            if (exponent & 1)
                result = (result * value) % modulus;
            value = (value * value) % modulus;
            exponent >>= 1;
        }
        return result;
    }

    void gost(const std::string &filename, cpp_int &p, cpp_int &q, cpp_int &a, cpp_int &y)
    {
        cpp_int pmin = 1;
        pmin <<= 1023;
        pmin -= 1;
        std::cout << pmin << '\n';

        mt11213b base_gen(clock());
        independent_bits_engine<mt11213b, 256, cpp_int> gen256(base_gen);
        independent_bits_engine<mt11213b, 1024, cpp_int> gen1024(base_gen);
        cpp_int b = 0;
        p = 1;
        do
        {
            q = gen256();
            if (miller_rabin_test(q, 25))
            {
                b = pmin / q;
                p += q * (b++);
                while (!miller_rabin_test(p, 25))
                {
                    b++;
                    p += q;
                }
                break;
            }
        } while (true);
        std::cout << "p - " << p << '\n';
        std::cout << "q - " << q << '\n';
        b = (p - 1) / q;
        a = -1;
        cpp_int g = 0;
        while (a < 0)
        {
            g = gen1024() % (p - 1);
            a = powm(g, b, p);
        }
        std::cout << "a - " << a << ' ' << powm(a, q, p) << '\n';
        cpp_int h = hashFile(filename, q);
        cpp_int x = gen256() % q;
        y = powm(a, x, p);
        std::cout << "h - " << h << '\n';
        cpp_int k = 0;
        cpp_int r = 0;
        cpp_int s = 0;
        do
        {
            k = gen256() % (q - 1) + 1;
            r = powm(a, k, p);
            r = r % q;
            if (r == 0)
            {
                continue;
            }
            s = (k * h + x * r) % q;
            if (s != 0)
            {
                break;
            }
        } while (true);

        std::stringstream outdata;
        outdata << r;
        outdata << '\n';
        outdata << s;
        std::string result = outdata.str();
        fillFile("gost.txt", result);
    }
}
namespace unsign
{
    bool elgamal(const std::string &filename, const long long &P, const long long &g, const long long &y)
    {
        std::stringstream file(readFile("elgamal.txt"));
        long long r;
        file >> r;
        long long s;
        file >> s;

        long long h = hashFile(filename, P);

        long long a = basic::powmod(y, r, P);
        long long b = basic::powmod(r, s, P);
        std::cout << "1 - " << (a * b) % P << '\n';
        std::cout << "2 - " << basic::powmod(g, h, P) << '\n';
        return ((a * b) % P) == basic::powmod(g, h, P);
    }
    bool RSA(const std::string &filename, const long long &N, const long long &d)
    {

        long long h = hashFile(filename, N);

        std::string s1 = readFile("RSA.txt");
        long long s = std::strtoll(s1.c_str(), 0, 10);
        std::cout << "s " << s << std::endl;

        long long e = basic::powmod(s, d, N);
        std::cout << "e " << e << std::endl;
        std::cout << "h " << h << std::endl;
        return e == h;
    }

    bool gost(const std::string &filename, const cpp_int &p, const cpp_int &q, const cpp_int &a, const cpp_int &y)
    {

        std::stringstream file(readFile("gost.txt"));
        cpp_int r;
        file >> r;
        cpp_int s;
        file >> s;
        std::cout << "r - " << r << '\n';
        std::cout << "s - " << s << '\n';
        cpp_int h = hashFile(filename, q);
        if ((r <= 0) || (s >= q))
        {
            return false;
        }

        cpp_int h_ = boost::integer::mod_inverse(h, q);

        cpp_int u1 = (h_ * s) % q;
        cpp_int u2 = (h_ * r * -1) % q;
        u2 += q;
        std::cout << "u1 - " << u1 << '\n';
        std::cout << "u2 - " << u2 << '\n';
        cpp_int x1 = powm(a, u1, p);
        cpp_int x2 = powm(y, u2, p);
        cpp_int v = (x1 * x2) % p % q;
        return v == r;
    }

}