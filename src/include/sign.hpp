#include <cipher.hpp>
#include <iostream>
#include <fstream>
#include <sha256.hpp>
#include <sstream>

namespace sign
{
    void RSA(const std::string &filename, long long &N, long long &d);
}

namespace unsign
{
    bool RSA(const std::string &filename, const long long &N, const long long &d);
}