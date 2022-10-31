#include <cipher.hpp>
#include <basic.hpp>
#include <iostream>

int main(/*int argc, char *argv[]*/)
{
    /*
        long long c1, d1;
        long long c2, d2;

        long long P;
        P = basic::simpleSafeNumber(100);
        std::cout << "P: " << P << std::endl;

        cipher::init::shamira(c1, d1, P, 100);
        std::cout << "c: " << c1 << " d:" << d1 << std::endl;
        cipher::init::shamira(c2, d2, P, 100);
        std::cout << "c: " << c2 << " d:" << d2 << std::endl;

        long long m = rand() % (P - 1) + 1;
        long long x = cipher::encode::shamira(m, c1, c2, P);
        std::cout << "message: " << m << " encode: " << x << std::endl;

        std::cout << "message: " << x << " decode: " << cipher::decode::shamira(x, d1, d2, P) << '\n'
                  << std::endl;

        long long a = 0, b = 0;

        P = basic::simpleSafeNumber(100);
        std::cout << "P - " << P << std::endl;
        if (P == 5)
        {
            P = 47;
        }
        x = P;
        while (x >= P)
        {
            x = basic::simpleSafeNumber(100);
        }
        std::cout << "x - " << x << std::endl;
        long long g = basic::getG(P);
        m = rand() % (P - 1) + 1;
        long long y = basic::powmod(g, x, P);

        std::cout << P << ' ' << x << ' ' << g << ' ' << a << ' ' << b << std::endl;
        cipher::encode::elgamal(m, P, g, a, b, y);
        std::cout << "message: " << m << std::endl
                  << "decoded message: " << cipher::decode::elgamal(b, a, P, x) << std::endl;

        */
    long long P1 = basic::simpleSafeNumber(100);
    long long Q1 = basic::simpleSafeNumber(100);

    long long N = 0;
    long long c = 0;
    long long d = 0;

    cipher::init::RSA(P1, Q1, c, d, N);

    long long m = rand() % N + 1;
    std::cout << m << " < " << N << '\n';

    long long e = cipher::encode::RSA(m, d, N);
    std::cout << m << " -> " << e << " -> " << cipher::decode::RSA(e, c, N) << '\n';

    std::cout << '\n';

    char e1 = cipher::encode::vernam('a', 'g');

    std::cout << 'a' << ' ' << static_cast<int>(e1) << ' ' << cipher::decode::vernam(e1, 'g') << '\n';
}