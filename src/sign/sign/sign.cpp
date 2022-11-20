#include <sign.hpp>

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
    void gost(const std::string &filename, long long &p, long long &q, long long &a, long long &y)
    {
        long long pup = (static_cast<long long>(1) << 31) - 1;
        std::cout << pup << '\n';
        long long qup = (static_cast<long long>(1) << 16) - 1;
        std::cout << qup << '\n';
        q = basic::simpleSafeNumber(qup);
        long long qcount = (pup / 2) / q;
        long long qcur = q * (qcount + 1);
        while (basic::testFerma(qcur + 1, 500) == false)
        {
            qcur += q;
        }
        p = qcur + 1;

        std::cout << "p - " << p << '\n';
        std::cout << "q - " << q << '\n';
        long long b = (p - 1) / q;
        a = -1;
        long long g = 0;
        while (a < 0)
        {
            g = rand() % (p - 1);
            a = basic::powmod(g, b, p);
        }
        std::cout << "a - " << a << ' ' << basic::powmod(a, q, p) << '\n';
        long long h = hashFile(filename, q);
        long long x = basic::simpleSafeNumber(q);
        y = basic::powmod(a, x, p);

        long long k = 0;
        long long r = 0;
        long long s = 0;
        do
        {
            k = rand() % (q - 1) + 1;
            r = basic::powmod(a, k, p) % q;
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

    bool gost(const std::string &filename, const long long &p, const long long &q, const long long &a, const long long &y)
    {

        std::stringstream file(readFile("gost.txt"));
        long long r;
        file >> r;
        long long s;
        file >> s;
        std::cout << "r - " << r << '\n';
        std::cout << "s - " << s << '\n';
        long long h = hashFile(filename, q);
        if ((r <= 0) || (s >= q))
        {
            return false;
        }

        long long h_ = basic::reverse(q, h);

        long long u1 = (h_ * s) % q;
        long long u2 = (h_ * r * -1) % q;
        u2 += q;
        std::cout << "u1 - " << u1 << '\n';
        std::cout << "u2 - " << u2 << '\n';
        long long v = ((basic::powmod(a, u1, p) * basic::powmod(y, u2, p)) % p) % q;
        return v == r;
    }

}