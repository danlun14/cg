#pragma once
#ifndef LABS_LAB5_H
#define LABS_LAB5_H

#include <boost/uuid/detail/md5.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/miller_rabin.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/integer/extended_euclidean.hpp>
#include <boost/multiprecision/integer.hpp>
#include <boost/integer/mod_inverse.hpp>
#include <fstream>

using namespace boost::multiprecision;
using namespace boost::random;
using boost::multiprecision::powm;
using boost::uuids::detail::md5;

cpp_int powM(cpp_int value, cpp_int exponent, cpp_int modulus);

cpp_int md5_to_Int(const cpp_int &n);

class Server
{

    cpp_int N;
    cpp_int c;
    cpp_int d;

    std::vector<cpp_int> electorList;

public:
    std::vector<std::pair<cpp_int, cpp_int>> bulletinList;

    int voteYes = 0;
    int voteNo = 0;
    int corruptedBulletins = 0;

public:
    Server()
    {
        cpp_int q = 0;
        cpp_int p = 0;
        do
        {
            q = GetPrime();
            p = 2 * q + 1;
        } while (!miller_rabin_test(p, 2));

        N = p * q;
        cpp_int phi = (p - 1) * (q - 1);

        boost::mt19937 eng;
        boost::uniform_int<cpp_int> range(0, phi);
        boost::variate_generator<mt19937, boost::uniform_int<cpp_int>> rand(eng, range);
        do
        {
            d = rand();
        } while (gcd(d, phi) != 1);
        auto exGCD = boost::integer::extended_euclidean(d, phi);

        //        std::cout << "Q = " << q << '\n';
        //        std::cout << "P = " << p << '\n';
        //
        //        std::cout << "N = " << N << '\n';
        //        std::cout << "Phi = " << phi << '\n';
        //
        //        std::cout << "D = " << d << '\n';
        //        std::cout << "gcd = " << exGCD.gcd << '\n';
        //        std::cout << "X = " << exGCD.x << '\n';
        //        std::cout << "Y = " << exGCD.y << '\n';

        c = boost::integer::mod_inverse(d, phi);

        //        std::cout << "C = " << c << '\n';
        //        std::cout << "powm = " << powm(c,d, phi) << '\n';
    }

    cpp_int GetPrime()
    {
        mt11213b base_gen(clock());
        independent_bits_engine<mt11213b, 1024, cpp_int> gen(base_gen);

        // Generate some large random primes
        // Note 25 trials of Miller-Rabin
        // likelihood that number is prime
        cpp_int n;
        do
        {
            n = gen();
        } while (!miller_rabin_test(n, 25));
        return n;
    }

    const cpp_int &getN() const
    {
        return N;
    }

    const cpp_int &getD() const
    {
        return d;
    }

    cpp_int registerBulletin(const cpp_int &h_)
    {
        electorList.emplace_back(h_);

        return powM(h_, c, N);
    }

    bool checkBulletin(const cpp_int &n, const cpp_int &s)
    {
        cpp_int hash(md5_to_Int(n));

        //        std::cout << "S =  \n" << s << '\n';
        if (hash != powm(s, d, N))
        {
            corruptedBulletins++;
            return false;
        }

        switch (static_cast<unsigned char>(n))
        {
        case 0:
            corruptedBulletins++;
            break;
        case 1:
            voteYes++;
            break;
        case 2:
            voteNo++;
            break;
        }
        bulletinList.emplace_back(std::make_pair(n, s));
        return true;
    }
};

class Client
{
public:
    cpp_int rnd;
    unsigned char vote;
    cpp_int r;
    cpp_int h_;
    cpp_int s = 0;
    cpp_int n;

    const cpp_int &getS() const
    {
        return s;
    }

    const cpp_int &getN() const
    {
        return n;
    }

    const cpp_int &getH_() const
    {
        return h_;
    }

    Client(const cpp_int &N, const cpp_int &D)
    {
        rnd = GetPrime();

        Vote();

        n = rnd | vote;

        mt11213b base_gen(clock());
        independent_bits_engine<mt11213b, 1024, cpp_int> gen(base_gen);

        do
        {
            r = gen();
        } while (gcd(r, N) != 1);

        cpp_int hash_num = (md5_to_Int(n));

        h_ = (hash_num % N) * powM(r, D, N);
    }

    cpp_int GetPrime()
    {
        mt11213b base_gen(clock());
        independent_bits_engine<mt11213b, 512, cpp_int> gen(base_gen);

        // Generate some large random primes
        // Note 25 trials of Miller-Rabin
        // likelihood that number is prime
        cpp_int num;
        do
        {
            num = gen();
        } while (!miller_rabin_test(num, 25));
        return n;
    }

    void Vote()
    {
        srand(time(NULL));

        vote = rand() % 3;
    }

    void computeSign(const cpp_int &s_, const cpp_int &N)
    {
        s = s_ * boost::integer::mod_inverse(r, N) % N;
    }
};

cpp_int powM(cpp_int value, cpp_int exponent, cpp_int modulus)
{
    value %= modulus;
    cpp_int result = 1;
    while (exponent > 0)
    {
        if (exponent & 1)
            result = (result * value) % modulus;
        value = (value * value) % modulus;
        exponent >>= 1;
    }
    return result;
}

cpp_int md5_to_Int(const cpp_int &n)
{
    md5 hash;
    md5::digest_type digest;

    hash.process_bytes(n.str().data(), n.str().size());
    hash.get_digest(digest);

    std::string hash_str = std::to_string(digest[0]).append(std::to_string(digest[1])).append(std::to_string(digest[2])).append(std::to_string(digest[3]));

    cpp_int result(hash_str);
    //    std::cout << "hash :\n" << hash_str << '\n';

    return result;
}

#endif // LABS_LAB5_H