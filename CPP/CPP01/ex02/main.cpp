#include <string>
#include <iostream>

int main()
{
    std::string brain = "HI THIS IS BRAIN";
    std::string* stringPTR = &brain;
    std::string& stringREF = brain;

    std::cout<<&brain<<" : memory address of the string."<<std::endl;
    std::cout<<stringPTR<<" : memory address held by stringPTR."<<std::endl;
    std::cout<<&stringREF<<" : memory address held by stringREF."<<std::endl<<std::endl;
    std::cout<<brain<<" : value of the string."<<std::endl;
    std::cout<<*stringPTR<<" : value pointed to by stringPTR."<<std::endl;
    std::cout<<stringREF<<" : value pointed to by stringREF."<<std::endl;
    return (0);
}