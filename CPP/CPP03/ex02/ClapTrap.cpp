#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string &name)
    : Name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap Constructor called for " << Name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    *this = other;
    std::cout << "ClapTrap Copy Constructor called for " << Name << std::endl;
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
    std::cout << "ClapTrap Assignment Operator called for " << Name << std::endl;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destructor called for " << Name << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (energyPoints > 0 && hitPoints > 0)
    {
        energyPoints--;
        std::cout << "ClapTrap " << Name << " attacks " << target
                  << ", causing " << attackDamage << " points of damage!" << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << Name << " can't attack due to insufficient energy or health." << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints > 0)
    {
        hitPoints -= amount;
        std::cout << "ClapTrap " << Name << " takes " << amount << " damage! Remaining hit points: " << hitPoints << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << Name << " is already out of hit points!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (energyPoints > 0 && hitPoints > 0)
    {
        energyPoints--;
        hitPoints += amount;
        std::cout << "ClapTrap " << Name << " repairs itself by " << amount << " hit points!" << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << Name << " can't repair due to insufficient energy or health." << std::endl;
    }
}

std::string ClapTrap::getName() const { return Name; }
int ClapTrap::getHitPoints() const { return hitPoints; }
int ClapTrap::getEnergyPoints() const { return energyPoints; }
int ClapTrap::getAttackDamage() const { return attackDamage; }

void ClapTrap::setHitPoints(int hp) { hitPoints = hp; }
void ClapTrap::setEnergyPoints(int ep) { energyPoints = ep; }
void ClapTrap::setAttackDamage(int ad) { attackDamage = ad; }
