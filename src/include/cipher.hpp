#include <basic.hpp>

namespace cipher
{
    namespace init
    {
        void shamira(long long &C, long long &D, long long P, long long up);

        void RSA(long long P, long long Q, long long &C, long long &D, long long &N);

        void elgamal(long long P, long long x, long long &g, long long &y);
    }

    namespace encode
    {
        long long shamira(long long x, long long ca, long long cb, long long p);

        void elgamal(long long m, long long P, long long g, long long &a, long long &b, long long y);

        long long RSA(long long m, long long d, long long N);

        template <typename T>
        T vernam(T m, T k)
        {
            return m ^ k;
        }
    }

    namespace decode
    {
        long long shamira(long long x, long long da, long long db, long long p);

        long long elgamal(long long b, long long a, long long P, long long x);

        long long RSA(long long e, long long c, long long N);

        template <typename T>
        T vernam(T e, T k)
        {
            return e ^ k;
        }
    }
}