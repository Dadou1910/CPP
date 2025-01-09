#include "ClapTrap.hpp"

int main()
{
    const std::string personA = "Jean";
    const std::string personB = "Lola";

    ClapTrap robot1(personA);
    ClapTrap robot2(personB);

    robot1.attack(personB);
    robot2.takeDamage(5);

    robot2.beRepaired(3);

    robot2.attack(personA);
    robot1.takeDamage(2);

    robot1.attack(personB);
    robot2.takeDamage(5);

    robot2.beRepaired(3);

    robot2.attack(personA);
    robot1.takeDamage(2);

    robot1.attack(personB);
    robot2.takeDamage(5);

    robot2.beRepaired(3);

    robot2.attack(personA);
    robot1.takeDamage(2);

    robot1.attack(personB);
    robot2.takeDamage(5);

    robot2.beRepaired(3);

    robot2.attack(personA);
    robot1.takeDamage(2);


    robot1.attack(personB);
    robot2.takeDamage(5);

    robot2.beRepaired(3);

    robot2.attack(personA);
    robot1.takeDamage(2);

    return (0);
}
