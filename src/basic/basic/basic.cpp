#include <basic.hpp>
#include <BigInt.hpp>

class BigInt;

namespace basic
{

    void generatorTest(int size)
    {
        auto *arr = new int[size];
        PRNG gen;
        for (int i = 0; i < size; i++)
        {
            arr[i] = 0;
        }
        for (int i = 0; i < size * size; i++)
        {
            arr[getRand(gen, 0, size)] += 1;
        }
        for (int i = 0; i < size; i++)
        {
            std::cout << arr[i] << '\n';
        }
        delete[] arr;
    }

    size_t getRand(PRNG &generator, size_t start, size_t end)
    {
        std::uniform_int_distribution<size_t> distribution(start, end);
        return distribution(generator.engine);
    }

    long long powmod(long long a, long long x, long long p)
    {
        long long result = 1;
        long long x0 = 1;
        long long bitcounter = x;
        long long amod = 0;
        while (x0 < x)
        {
            amod = 1;
            if (bitcounter % 2 == 1)
            {
                amod = a % p;
            }
            result *= amod;
            result %= p;

            bitcounter /= 2;
            a = (a * a) % p;
            x0 *= 2;
        }
        return result;
    }

    long long gcd(long long a, long long b)
    {
        long long r;
        while (b != 0)
        {
            r = a % b;
            a = b;
            b = r;
        }
        return a;
    }

    std::vector<long long> extendedEuclidean(long long a, long long b)
    {
        std::vector<long long> U, V, T;
        T.resize(3);
        U.push_back(a);
        U.push_back(1);
        U.push_back(0);
        V.push_back(b);
        V.push_back(0);
        V.push_back(1);
        long long q;
        while (V.at(0) != 0)
        {
            q = U.at(0) / V.at(0);
            T.at(0) = U.at(0) % V.at(0);
            T.at(1) = U.at(1) - q * V.at(1);
            T.at(2) = U.at(2) - q * V.at(2);
            U = V;
            V = T;
        }
        return U;
    }

    long long reverse(long long m, long long c)
    {
        std::vector<long long> U, V, T;
        T.resize(2);
        U.push_back(m);
        U.push_back(0);
        V.push_back(c);
        V.push_back(1);
        long long q;
        while (V.at(0) != 0)
        {
            q = U.at(0) / V.at(0);
            T.at(0) = U.at(0) % V.at(0);
            T.at(1) = U.at(1) - q * V.at(1);
            U = V;
            V = T;
        }
        if (U.at(1) < 0)
        {
            U.at(1) += m;
        }
        return U.at(1);
    }

    long long coPrime(long long p, long long up = 65535)
    {
        PRNG gen;
        long long rn = 0;
        do
        {
            rn = getRand(gen, 2, up);
        } while (gcd(p, rn) != 1);
        return rn;
    }

    long long euler(long long p)
    {
        PRNG gen;
        long long p0 = p;
        long long counter = 0;
        do
        {
            if (gcd(p0, p) == 1)
            {
                counter++;
            }

        } while (--p > 0);
        return counter;
    }

    bool testFerma(long long p, int k)
    {
        if (p == 2)
            return true;
        if (p % 2 == 0)
        {
            return false;
        }
        for (int i = 0; i < k; ++i)
        {
            long long a = rand() % (p - 1) + 1;
            if (gcd(a, p) != 1 || powmod(a, p - 1, p) != 1)
            {
                return false;
            }
        }
        return true;
    }

    long long simpleSafeNumber(long long up)
    {
        PRNG gen;
        while (true)
        {
            long long rn = getRand(gen, 2, up);

            if (testFerma(rn, 60))
            {
                long long rn2 = rn * 2 + 1;
                if (testFerma(rn2, 60))
                {
                    return rn2;
                }
            }
        }
    }
    long long getG(long long P)
    {
        PRNG gen;
        long long curr = 2;
        long long Q = (P - 1) / 2;
        do
        {
            if (powmod(curr, Q, P) != 1)
            {
                return curr;
            }
            curr++;
        } while (true);
    }
}