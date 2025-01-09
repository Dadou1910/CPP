#include "Zombie.hpp"

Zombie::Zombie() : Name("") {}
Zombie::Zombie(const std::string &name) : Name(name) {}
Zombie::~Zombie()
{
    std::cout << Name << " has been destroyed." << std::endl;
}
void Zombie::announce(void)
{
    std::cout << Name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}