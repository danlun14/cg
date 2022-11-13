#include <iostream>
#include <sign.hpp>

int main()
{
    std::string ifile = "";
    std::cout << "Enter input filename:\n";
    std::cin >> ifile;

    long long N = 0, d = 0;
    sign::RSA(ifile, N, d);

    std::cout << "Enter filename to check:\n";
    std::cin >> ifile;

    std::cout << unsign::RSA(ifile, N, d) << '\n';
}