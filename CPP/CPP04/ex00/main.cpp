#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "=== TEST BASIQUE ===\n" << std::endl;
    const Animal *animal = new Animal();
    const Animal *dog = new Dog();
    const Animal *cat = new Cat();

    std::cout << "\n=== TEST DES TYPES ===\n" << std::endl;
    std::cout << "Animal type: " << animal->getType() << std::endl;
    std::cout << "Dog type: " << dog->getType() << std::endl;
    std::cout << "Cat type: " << cat->getType() << std::endl;

    std::cout << "\n=== TEST DES SONS ===" << std::endl;
    animal->makeSound();
    dog->makeSound();
    cat->makeSound();

    std::cout << "\n=== DESTRUCTION DES OBJETS ===\n" << std::endl;
    delete animal;
    delete dog;
    delete cat;

    std::cout << "\n=== TEST DES CONSTRUCTEURS ===\n" << std::endl;
    Dog dog1;
    Dog dog2(dog1);

    std::cout << "\n=== TEST DES OPÉRATEURS ===\n" << std::endl;
    Dog dog3;
    dog3 = dog1;

    std::cout << "\n=== TEST SUR LES OBJETS NORMAUX ===\n" << std::endl;
    Cat cat1;
    cat1.makeSound();

    std::cout << "\n=== TEST DE POINTEURS SUR DES CLASSES DE BASE ===\n" << std::endl;
    Animal *animalDog = new Dog();
    Animal *animalCat = new Cat();

    std::cout << "animalDog type: " << animalDog->getType() << std::endl;
    std::cout << "animalCat type: " << animalCat->getType() << std::endl;

    animalDog->makeSound();
    animalCat->makeSound();

    std::cout << "\n=== FIN DES TESTS ===\n" << std::endl;
    delete animalDog;
    delete animalCat;

    return 0;
}

