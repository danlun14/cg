#include <cipher.hpp>
#include <iostream>

namespace cipher
{
    namespace init
    {
        void shamira(long long &C, long long &D, long long P, long long up = 1000)
        {
            basic::PRNG gen;
            long long c, d;
            while (1)
            {
                c = basic::getRand(gen, 2, up);
                d = basic::getRand(gen, 2, up);
                if ((c * d) % (P - 1) == 1)
                {
                    C = c;
                    D = d;
                    break;
                }
            }
        }
        void RSA(long long P, long long Q, long long &C, long long &D, long long &N)
        {
            N = P * Q;
            long long fi = (P - 1) * (Q - 1);

            D = basic::coPrime(fi, fi);
            C = basic::reverse(fi, D);
        }
    }

    namespace encode
    {
        long long shamira(long long m, long long ca, long long cb, long long P)
        {
            long long x1, x2;

            x1 = basic::powmod(m, ca, P);
            x2 = basic::powmod(x1, cb, P);

            return x2;
        }

        void elgamal(long long m, long long P, long long g,
                     long long &a, long long &b, long long y)
        {
            basic::PRNG gen;
            long long k = basic::getRand(gen, 0, P - 2);
            a = basic::powmod(g, k, P);
            b = (static_cast<BigInt>(basic::powmod(y, k, P)) * m % P).to_long_long();
        }

        long long RSA(long long m, long long d, long long N)
        {
            return basic::powmod(m, d, N);
        }

    }

    namespace decode
    {
        long long shamira(long long x, long long da, long long db, long long P)
        {
            long long x1;

            x1 = basic::powmod(x, da, P);
            return basic::powmod(x1, db, P);
        }

        long long elgamal(long long b, long long a, long long P, long long x)
        {
            return static_cast<BigInt>((basic::powmod(a, P - 1 - x, P)) * b % P).to_long_long();
        }

        long long RSA(long long e, long long c, long long N)
        {
            return basic::powmod(e, c, N);
        }

    }
}