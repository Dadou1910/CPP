#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    Animal *animals[4];

    std::cout << "\n=== Création des animaux ===" << std::endl;
    for (int i = 0; i < 2; ++i)
        animals[i] = new Dog();
    for (int i = 2; i < 4; ++i)
        animals[i] = new Cat();

    std::cout << "\n=== Test des idées ===" << std::endl;
    Dog *dog = dynamic_cast<Dog *>(animals[0]);
    Cat *cat = dynamic_cast<Cat *>(animals[2]);

    dog->setIdea(0, "Chase the cat!");
    cat->setIdea(0, "Sleep all day!");

    std::cout << "Dog idea: " << dog->getIdea(0) << std::endl;
    std::cout << "Cat idea: " << cat->getIdea(0) << std::endl;

    std::cout << "\n=== Destruction des animaux ===" << std::endl;
    for (int i = 0; i < 4; ++i)
        delete animals[i];

    std::cout << "\n=== Fin du programme ===" << std::endl;
    return 0;
}


