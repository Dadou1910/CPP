#include "HumanB.hpp"

HumanB::HumanB(const std::string &name) : Name(name), WeaponPtr(0) {}

void HumanB::setWeapon(Weapon& weapon)
{
    WeaponPtr = &weapon;
}

void HumanB::attack() const
{
    if (WeaponPtr)
        std::cout << Name << " attacks with their " << WeaponPtr->getType() << std::endl;
    else
        std::cout << Name << " has no weapon to attack with!" << std::endl;
}