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

namespace sign
{

    void RSA(const std::string &filename, long long &N, long long &d)
    {

        std::string filedata = readFile(filename);

        std::string filehash = SHA256(filedata.c_str());
        std::cout << filehash << '\n';
        filehash.erase(3, filehash.size() - 3);
        long long h = std::strtoll(filehash.c_str(), 0, 16);

        long long P = basic::simpleSafeNumber(20000);
        long long Q = basic::simpleSafeNumber(20000);
        std::cout << "P " << P << std::endl;
        std::cout << "Q " << Q << std::endl;

        N = 0;
        long long c = 0; // close
        d = 0;           // open

        cipher::init::RSA(P, Q, c, d, N);
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
}
namespace unsign
{
    bool RSA(const std::string &filename, const long long &N, const long long &d)
    {

        std::string filedata = readFile(filename);
        std::string filehash = SHA256(filedata.c_str());
        filehash.erase(3, filehash.size() - 3);
        long long h = std::strtoll(filehash.c_str(), 0, 16);

        std::string s1 = readFile("RSA.txt");
        long long s = std::strtoll(s1.c_str(), 0, 10);
        std::cout << "s " << s << std::endl;

        long long e = basic::powmod(s, d, N);
        std::cout << "e " << e << std::endl;
        std::cout << "h " << h << std::endl;
        return e == h;
    }
}