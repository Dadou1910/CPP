#ifndef HUMANA_HPP
#define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
private:
    std::string Name;
    Weapon& WeaponRef;

public:
    HumanA(const std::string& name, Weapon& weapon);
    void attack() const;
};

#endif