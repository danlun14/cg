#include <basic.hpp>
#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <cipher.hpp>

void shuffledeck(std::vector<long long> &v)
{
    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(v.begin(), v.end(), g);
}

struct player
{
    long long card1;
    long long card2;
    long long C;
    long long D;
};

template <class T>
void serializevector(const std::vector<T> &v)
{
    std::cout << "Vector: size - " << v.size() << " capacity - " << v.capacity() << '\n';
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";
}
int main()
{
    int ccards = 0, cplayers = 0;
    std::cout << "Enter numbers of players\n";
    std::cin >> cplayers;
    std::cout << "Enter numbers of cards\n";
    std::cin >> ccards;
    if (cplayers * 2 + 5 > ccards)
    {
        std::cout << "Game is unplayable: not enough " << cplayers * 2 + 5 - ccards << " cards!\n";
        return -1;
    }
    long long P = basic::simpleSafeNumber(200000);
    std::vector<long long> deck;
    deck.reserve(ccards);
    for (int i = 2; i < ccards + 2; i++)
    {
        deck.push_back(i);
    }
    // serializevector(deck);
    shuffledeck(deck);
    // serializevector(deck);
    std::vector<player> players;
    players.reserve(cplayers);
    for (int i = 0; i < cplayers; i++)
    {
        player guy;

        cipher::init::shamira(guy.C, guy.D, P, P - 1);

        players.push_back(guy);
    }

    for (int i = 0; i < cplayers; i++)
    {
        player &guy = players.at(i);
        for (auto &item : deck)
        {
            item = basic::powmod(item, guy.C, P);
        }

        shuffledeck(deck);
    }
    serializevector(deck);
    for (int i = 0; i < cplayers; i++)
    {
        player &guy = players.at(i);
        guy.card1 = *(deck.end() - 1);
        deck.erase(deck.end() - 1);
        guy.card2 = *(deck.end() - 1);
        deck.erase(deck.end() - 1);
        std::cout << "Player " << i << " code: " << guy.card1 << ' ' << guy.card2 << '\n';

        ccards -= 2;
    }
    std::cout << "table:\n";
    for (int i = 0; i < 5; i++)
    {
        auto &item = *(deck.end() - 1);
        deck.erase(deck.end() - 1);
        ccards -= 1;
        for (int i = 0; i < cplayers; i++)
        {
            player &guy = players.at(i);
            item = basic::powmod(item, guy.D, P);
        }
        std::cout << item << ' ';
        if ((i == 2) || (i == 3))
        {
            std::cout << "  ";
        }
    }
    std::cout << '\n';

    for (int i = 0; i < cplayers; i++)
    {
        std::cout << i
                  << std::endl;
        player &guy = players.at(i);
        for (int j = i + 1; j != i; j++)
        {
            if (j == cplayers)
            {
                if (i == 0)
                {
                    break;
                }
                j = 0;
            }
            player &checkguy = players.at(j);
            guy.card1 = basic::powmod(guy.card1, checkguy.D, P);
            guy.card2 = basic::powmod(guy.card2, checkguy.D, P);
            std::cout << i << ' ' << j << '\n';
        }
        guy.card1 = basic::powmod(guy.card1, guy.D, P);
        guy.card2 = basic::powmod(guy.card2, guy.D, P);

        std::cout << "Player " << i << " cards: " << guy.card1 << ' ' << guy.card2 << '\n';
    }
}