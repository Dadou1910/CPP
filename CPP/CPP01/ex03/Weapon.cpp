#include "Weapon.hpp"

const std::string& Weapon::getType() const
{
    return (this->type);
}

void Weapon::setType(const std::string& ref)
{
    this->type = ref;
}
