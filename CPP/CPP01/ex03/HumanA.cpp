#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& weapon)
       : Name(name), WeaponRef(weapon) {}

void    HumanA::attack() const
{
    std::cout << HumanA::Name << " attacks with their "
             << HumanA::WeaponRef.getType() << std::endl;
}