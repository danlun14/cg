#include <algorithm>
#include <random>
#include <vector>
#include <iostream>
#include <fstream>

int main()
{
    std::ofstream filegraph("graph.rgr");
    std::ofstream filecycle("cycle.rgr");
    int n, m;
    std::cout << "Input n\n";
    std::cin >> n;
    std::cout << "Input m\n";
    std::cin >> m;
    if (n > m)
    {
        return 0;
    }
    filegraph << n << ' ' << m << '\n';
    std::vector<int> v;
    v.reserve(n);
    for (int i = 0; i < n; i++)
    {
        v.push_back(i);
    }
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(v.begin(), v.end(), g);
    for (int i = 0; i < n - 1; i++)
    {
        filecycle << v.at(i) << ' ';
        filegraph << v.at(i) << ' ' << v.at(i + 1) << '\n';
    }
    filecycle << v.at(n - 1) << ' ';
    filegraph << v.at(n - 1) << ' ' << v.at(0) << '\n';
    m -= n;
    while (m--)
    {
        int a = g() % n;
        int b = g() % n;
        if (b == a)
        {
            m++;
        }
        else
        {
            filegraph << a << ' ' << b << '\n';
        }
    }
}