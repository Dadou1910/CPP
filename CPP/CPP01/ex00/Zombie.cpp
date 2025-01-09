#include "Zombie.hpp"

Zombie::Zombie(const std::string &name) : Name(name) {};

void Zombie::announce(void)
{
    std::cout << Name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}


Zombie::~Zombie()
{
    std::cout << "Zombie " << Name << " has been destroyed." << std::endl;
}