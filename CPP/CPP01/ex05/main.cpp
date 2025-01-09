#include "Harl.hpp"

int main()
{
    Harl harl;
    long unsigned int idx = 5;
    std::string msg[6] = {"", "INFO", "DFG", "WARNING", "ERROR", "DEBUG"};

    if (idx < sizeof(msg) / sizeof(msg[idx]))
        harl.complain(msg[idx]);
    else
        std::cout << "Invalid index for msg array!" << std::endl;
    return (0);
}