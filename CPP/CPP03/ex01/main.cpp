#include "ScavTrap.hpp"

int main()
{
    ClapTrap clap1("Clappy");
    ClapTrap clap2("Trapster");

    std::cout << "\n--- ClapTrap Actions ---" << std::endl;
    clap1.attack("Enemy1");
    clap1.takeDamage(5);
    clap1.beRepaired(3);

    clap2.takeDamage(15);
    clap2.attack("Enemy2");
    clap2.beRepaired(5);

    std::cout << "\n--- ScavTrap Actions ---" << std::endl;
    ScavTrap scav1("Guardian");
    ScavTrap scav2("Protector");

    scav1.attack("Enemy3");
    scav1.takeDamage(20);
    scav1.beRepaired(10);
    scav1.guardGate();

    std::cout << "\n--- Copy Constructor and Assignment ---" << std::endl;
    ScavTrap scav3(scav1);
    scav3.guardGate();

    scav2 = scav1;
    scav2.attack("Enemy4");

    std::cout << "\n--- Test End ---" << std::endl;

    return 0;
}


