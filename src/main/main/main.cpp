#include <basic.hpp>
#include <BigInt.hpp>
#include <iostream>

class User
{
public:
    long long P;
    long long g;
    long long keypri;
    long long keypart;
    long long keypart2;
    long long key;
};

int main(/*int argc, char *argv[]*/)
{
    /*
        srand(time(nullptr));
        BigInt m;
        BigInt c;
        c = "618";
        m = "310";
        // BigInt a, b = basic::powmod(3, c, m);
        // a = "214451513515512351";
        // std::cout << a << ' ' << b << '\n';
        // std::cout << basic::gcd(c, d) << '\n';
        auto res = basic::extendedEuclidean(28, 19);
        std::cout << res.at(1) << ' ' << res.at(2) << '\n';

        std::cout << basic::powmod(5, 12, 7) << '\n';
        std::cout << basic::powmod(3, 21, 11) << '\n';
        std::cout << basic::powmod(7, 31, 17) << '\n';
        std::cout << basic::powmod(2, 10, 5) << '\n';
        std::cout << basic::powmod(5, 17, 11) << '\n';
        std::cout << basic::powmod(3, 15, 10) << '\n';
        std::cout << basic::powmod(7, 12, 9) << '\n';
        std::cout << basic::powmod(2, 11, 5) << '\n';

        c = 7;
        m = 11;
        res = basic::extendedEuclidean(m, c);
        std::cout << '\n'
                  << c << " * " << res.at(2) + m << " mod " << m << " = " << res.at(0) << '\n';
        c = 3;
        m = 11;
        res = basic::extendedEuclidean(m, c);
        std::cout << c << " * " << res.at(2) + m << " mod " << m << " = " << res.at(0) << '\n';
        c = 5;
        m = 9;
        res = basic::extendedEuclidean(m, c);
        std::cout << c << " * " << res.at(2) + m << " mod " << m << " = " << res.at(0) << '\n';
        c = 7;
        m = 13;
        res = basic::extendedEuclidean(m, c);
        std::cout << c << " * " << res.at(2) + m << " mod " << m << " = " << res.at(0) << '\n';
        c = 6;
        m = 7;
        res = basic::extendedEuclidean(m, c);
        std::cout << c << " * " << res.at(2) + m << " mod " << m << " = " << res.at(0) << '\n';
        c = 3;
        m = 10;
        res = basic::extendedEuclidean(m, c);
        std::cout << c << " * " << res.at(2) + m << " mod " << m << " = " << res.at(0) << '\n';
        c = 5;
        m = 11;
        res = basic::extendedEuclidean(m, c);
        std::cout << c << " * " << res.at(2) + m << " mod " << m << " = " << res.at(0) << '\n';
        c = 4;
        m = 7;
        res = basic::extendedEuclidean(m, c);
        std::cout << c << " * " << res.at(2) + m << " mod " << m << " = " << res.at(0) << '\n';
        c = 2;
        m = 9;
        res = basic::extendedEuclidean(m, c);
        std::cout << basic::reverse(m, c);
        std::cout << c << " * " << res.at(2) + m << " mod " << m << " = " << res.at(0) << '\n';

        std::cout << basic::testFerma(7, 30);
        std::cout << basic::testFerma(4, 30);
        std::cout << basic::testFerma(8, 30);
        std::cout << basic::testFerma(233, 60) << std::endl;
        // basic::generatorTest(1000);

        std::cout << basic::euler(11) << " --- " << std::endl;
        std::cout
            << basic::simpleSafeNumber(200) << "--- " << std::endl;
        std::cout << basic::simpleSafeNumber(200) << "--- " << std::endl;
        std::cout << basic::simpleSafeNumber(200) << "--- " << std::endl;
        std::cout << basic::simpleSafeNumber(200) << "--- " << std::endl;
        std::cout << basic::coPrime(15, 40) << " --- " << std::endl;
    */
    User Alice;
    User Bob;

    long long P, g;
    P = basic::simpleSafeNumber(1000);
    g = basic::getG(P);

    std::cout
        << "P: " << P << ' ' << "g: " << g << std::endl;

    Alice.P = P;
    Alice.g = g;

    Bob.P = P;
    Bob.g = g;

    Alice.keypri = basic::simpleSafeNumber(1000);
    std::cout << "Alice private key: " << Alice.keypri << std::endl;

    Bob.keypri = basic::simpleSafeNumber(1000);
    std::cout << "Bob private key: " << Bob.keypri << std::endl;

    Alice.keypart = basic::powmod(Alice.g, Alice.keypri, Alice.P);
    Bob.keypart = basic::powmod(Bob.g, Bob.keypri, Bob.P);
    std::cout << "Alice open key: " << Alice.keypart << std::endl;
    std::cout << "Bob open key: " << Bob.keypart << std::endl;

    Alice.keypart2 = Bob.keypart; //обмен открытыми ключами
    Bob.keypart2 = Alice.keypart;

    Alice.key = basic::powmod(Alice.keypart2, Alice.keypri, Alice.P);
    Bob.key = basic::powmod(Bob.keypart2, Bob.keypri, Bob.P);

    std::cout << "Alice final key: " << Alice.key << std::endl;
    std::cout << "Bob final key: " << Bob.key << std::endl;
}