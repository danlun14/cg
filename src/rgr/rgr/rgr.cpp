#include <fstream>
#include <vector>
#include <iostream>
#include <iterator>

#include <algorithm>
#include <random>

#include <cipher.hpp>
#include <basic.hpp>

#include <iomanip>

int main()
{
    std::vector<std::vector<long long>> H, G, F; // without size
    std::ifstream filegraph("graph.rgr");
    std::ifstream filecycle("cycle.rgr");
    std::vector<int> cycle;
    std::ofstream out("out.txt"); // откроем файл для вывод
    std::streambuf *coutbuf = std::cout.rdbuf();
    int n, m, tmp;
    filegraph >> n >> m;
    if (n > 5)
    {
        std::cout.rdbuf(out.rdbuf());
    }
    for (int i = 0; i < n; i++)
    {
        filecycle >> tmp;
        cycle.push_back(tmp);
    }
    long long C, D, N, P = basic::simpleSafeNumber(10000), Q = basic::simpleSafeNumber(10000);
    cipher::init::RSA(P, Q, C, D, N);
    H.reserve(n);
    G.reserve(n);
    F.reserve(n);
    H.resize(n);
    G.resize(n);
    F.resize(n);
    for (int i = 0; i < n; i++)
    {
        H[i].reserve(n);
        G[i].reserve(n);
        F[i].reserve(n);
        H[i].resize(n);
        G[i].resize(n);
        F[i].resize(n);
    }

    int i_, j_;
    while (m-- > 0)
    {
        filegraph >> i_ >> j_;
        G[i_][j_] = 1;
        // G[j_][i_] = 1;
    }
    for (int j = 0; j < n; j++)
    {
        // std::cout << cycle[j] << ' ';
    }
    // std::cout << '\n';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // std::cout << G[i][j] << ' ';
        }
        // std::cout << '\n';
    }
    std::vector<int> GtoH;
    GtoH.reserve(n);
    GtoH.resize(n);
    while (true)
    {
        for (int i = 0; i < n; i++)
        {
            GtoH[i] = i;
        }
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(GtoH.begin(), GtoH.end(), g);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                auto addingval = ((rd() % N) >> 1) << 1;
                H[GtoH[i]][GtoH[j]] = G[i][j] + addingval;
            }
        }
        for (int i = 0; i < n; i++)
        {
            // std::cout << GtoH[i] << ' ';
            for (int j = 0; j < n; j++)
            {
                // std::cout << H[i][j] << ' ';
            }
            // std::cout << '\n';
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {

                F[i][j] = cipher::encode::RSA(H[i][j], D, N);
            }
        }
        for (int i = 0; i < n; i++)
        {
            // std::cout << GtoH[i] << ' ';
            for (int j = 0; j < n; j++)
            {
                //  std::cout << F[i][j] << ' ';
            }
            //    std::cout << '\n';
        }
        int ans = 0;
        std::cout << " Choose question \n";
        std::cin >> ans;
        if (ans == 1)
        {
            std::cout << "\n cycle:\n";
            for (int i = 0; i < n - 1; i++)
            {
                i_ = i;
                j_ = i + 1;

                F[GtoH[cycle[i]]][GtoH[cycle[i + 1]]] = (cipher::decode::RSA(F[GtoH[cycle[i]]][GtoH[cycle[i + 1]]], C, N) & 1);
            }
            F[GtoH[cycle[n - 1]]][GtoH[cycle[0]]] = (cipher::decode::RSA(F[GtoH[cycle[n - 1]]][GtoH[cycle[0]]], C, N) & 1);
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    std::cout << std::setw(8) << F[i][j] << ' ';
                }
                std::cout << '\n';
            }
        }
        if (ans == 2)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    F[GtoH[cycle[i]]][GtoH[cycle[j]]] = cipher::decode::RSA(F[GtoH[cycle[i]]][GtoH[cycle[j]]], C, N);
                }
            }

            std::cout << "H~:\n";
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    std::cout << std::setw(8) << F[i][j] << ' ';
                }
                std::cout << '\n';
            }

            std::cout << "\n Indexes G to H:\n";
            for (int i = 0; i < n; i++)
            {
                std::cout << i << ' ';
            }
            std::cout << "\n";

            std::copy(GtoH.begin(), GtoH.end(), std::ostream_iterator<int>(std::cout, " "));
            std::cout << "\n";
        }
        if (ans == 3)
        {
            break;
        }
    }
    return 0;
}