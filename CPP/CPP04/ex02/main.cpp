#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "\n=== Tests avec des objets concrets ===" << std::endl;

    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << dog->getType() << " says: ";
    dog->makeSound();

    std::cout << cat->getType() << " says: ";
    cat->makeSound();

    delete dog;
    delete cat;

    // Code non valide:
    // Animal animal;  // Devrait provoquer une erreur de compilation

    std::cout << "\n=== Tests de polymorphisme ===" << std::endl;

    Animal* animals[4];
    animals[0] = new Dog();
    animals[1] = new Cat();
    animals[2] = new Dog();
    animals[3] = new Cat();

    for (int i = 0; i < 4; i++)
    {
        std::cout << "Animal " << i + 1 << " (" << animals[i]->getType() << ") says: ";
        animals[i]->makeSound();
    }

    std::cout << "\n=== Test terminé avec succès ===" << std::endl;
    for (int i = 0; i < 4; i++)
        delete animals[i];


    return 0;
}



