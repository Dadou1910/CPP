#include "Harl.hpp"

void Harl::debug()
{
    std::cout << "Yeah if something's happening tell me because I know everything better than everyone"
              << std::endl;
}

void Harl::info()
{
    std::cout << "You're about to do a huge mistake! I'm gonna tell your supervisor."
              << std::endl;
}

void Harl::warning()
{
    std::cout << "Aaaand there goes the huge mistake.. Luckily it doesn't make everything crash.. Yet."
              << std::endl;
}

void Harl::error()
{
    std::cout << "Oh. My. God. EVERYTHING CRASHED!" << std::endl;
}

void Harl::complain(std::string level)
{
    if (level.empty())
    {
        std::cout << "Invalid level!" << std::endl;
        return;
    }
    void (Harl::*actions[4])() = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < 4; ++i)
    {
        if (level == levels[i])
        {
            (this->*actions[i])();
            return;
        }
    }

    std::cout << "Invalid level!" << std::endl;
}