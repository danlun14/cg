#include <iostream>
#include <voting.hpp>

int main()
{
    Server serv;

    std::cout << "Server open:\nN - " << serv.getN() << "\nD - " << serv.getD() << std::endl;
    Client client(serv.getN(), serv.getD());

        client.computeSign(serv.registerBulletin(client.getH_()), serv.getN());

    std::cout << serv.checkBulletin(client.getN(), client.getS()) << '\n';
    std::cout << serv.voteYes << ' ' << serv.voteNo << ' ' << serv.corruptedBulletins << '\n';
}