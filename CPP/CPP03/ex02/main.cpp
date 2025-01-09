#include "FragTrap.hpp"

int main()
{
    FragTrap frag1("Fraggy");
    FragTrap frag2("Trappy");

    std::cout << "\n--- FragTrap Actions ---" << std::endl;
    frag1.attack("Enemy");
    frag1.takeDamage(30);
    frag1.beRepaired(20);

    frag2.highFivesGuys();

    std::cout << "\n--- Copy Test ---" << std::endl;
    FragTrap frag3(frag1);
    frag3.highFivesGuys();

    std::cout << "\n--- End Test ---" << std::endl;

    return 0;
}



