#include <iostream>
#include <sign.hpp>

int main()
{
    std::string ifile = "";
    std::cout << "Enter input filename:\n";
    std::cin >> ifile;

    long long N = 0, d = 0;
    // sign::RSA(ifile, N, d);

    long long P = 0, g = 0, y = 0;
    // sign::elgamal(ifile, P, g, y);

    long long p = 0, q = 0, a = 0, y2 = 0;
    sign::gost(ifile, p, q, a, y2);

    std::cout << "Enter filename to check:\n";
    std::cin >> ifile;

    // std::cout << unsign::RSA(ifile, N, d) << " RSA\n";

    // std::cout << unsign::elgamal(ifile, P, g, y) << " elgamal\n";

    std::cout << unsign::gost(ifile, p, q, a, y2) << " gost\n";
}