#pragma once

#include <BigInt.hpp>
#include <ctime>
#include <chrono>
#include <random>

#include <vector>

namespace basic
{
    struct PRNG
    {
        PRNG()
        {
            std::random_device device;
            auto newseed = device();
            engine.seed(newseed);
        }
        std::mt19937 engine;
    };

    void generatorTest(int size);
    size_t getRand(PRNG &generator, size_t start, size_t end);

    long long powmod(long long a, long long x, long long p);
    long long gcd(long long a, long long b);
    std::vector<long long> extendedEuclidean(long long a, long long b);
    long long reverse(long long m, long long c);

    long long coPrime(long long p, long long up);
    long long euler(long long p);

    bool testFerma(long long p, int k);
    long long simpleSafeNumber(long long up);

    long long getG(long long P);
}