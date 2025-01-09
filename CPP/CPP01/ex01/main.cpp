#include "Zombie.hpp"

int main()
{
    int N = 10;
    std::string name = "Brian";

    if (N <= 0)
    {
        std::cerr << "Error: N must be greater than 0." << std::endl;
        return 1;
    }
    Zombie* horde = zombieHorde(N, name);
    for (int i = 0; i < N; ++i)
        horde[i].announce();
    delete[] horde;
    return (0);
}