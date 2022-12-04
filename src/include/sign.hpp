#include <cipher.hpp>
#include <iostream>
#include <fstream>
#include <sha256.hpp>
#include <sstream>
#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;

namespace sign
{
    void elgamal(const std::string &filename, long long &P, long long &g, long long &y);
    void RSA(const std::string &filename, long long &N, long long &d);
    void gost(const std::string &filename, cpp_int &p, cpp_int &q, cpp_int &a, cpp_int &y);
}

namespace unsign
{
    bool elgamal(const std::string &filename, const long long &P, const long long &g, const long long &y);
    bool RSA(const std::string &filename, const long long &N, const long long &d);
    bool gost(const std::string &filename, const cpp_int &p, const cpp_int &q, const cpp_int &a, const cpp_int &y);
}