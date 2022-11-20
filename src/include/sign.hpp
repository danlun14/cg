#include <cipher.hpp>
#include <iostream>
#include <fstream>
#include <sha256.hpp>
#include <sstream>

namespace sign
{
    void elgamal(const std::string &filename, long long &P, long long &g, long long &y);
    void RSA(const std::string &filename, long long &N, long long &d);
    void gost(const std::string &filename, long long &p, long long &q, long long &a, long long &y);
}

namespace unsign
{
    bool elgamal(const std::string &filename, const long long &P, const long long &g, const long long &y);
    bool RSA(const std::string &filename, const long long &N, const long long &d);
    bool gost(const std::string &filename, const long long &p, const long long &q, const long long &a, const long long &y);
}