#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string &name)
         : Name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "Class constructor was called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    *this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    if (this != &other)
    {
        Name = other.Name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "Class destructor was called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (energyPoints <= 0)
    {
        std::cout << Name << " has no energy to attack!" << std::endl;
        return;
    }
    if (attackDamage < 0)
    {
        std::cout << Name << " cannot attack with negative damage!" << std::endl;
        return;
    }
    energyPoints -= 1;
    std::cout << "ClapTrap " << Name <<  " attacks " << target
              << " causing " << attackDamage << " points of damage!"
              << std::endl;
    std::cout << Name << " energy points left : " << energyPoints << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (amount > (unsigned int)hitPoints)
    {
        std::cout << Name << " took " << hitPoints << " damage and is destroyed!" << std::endl;
        hitPoints = 0;
    }
    else
    {
        hitPoints -= amount;
        std::cout << Name << " took " << amount << " damage!" << std::endl;
    }
    std::cout << Name << " hit points left : " << hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (energyPoints <= 0)
    {
        std::cout << Name << " has no energy to repair!" << std::endl;
        return;
    }
    hitPoints += amount;
    energyPoints -= 1;
    std::cout << Name << " repaired " << amount << " hit points!" << std::endl;
    std::cout << Name << " energy points left : " << energyPoints << std::endl;
}