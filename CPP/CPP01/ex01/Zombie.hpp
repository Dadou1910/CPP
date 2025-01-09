#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
private:
    std::string Name;

public:
    Zombie();
    Zombie(const std::string &name);
    ~Zombie();
    void announce(void);
};
    Zombie* zombieHorde(int N, std::string name);

#endif