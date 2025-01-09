#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        this->data = other.data;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: Could not open file.");

    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream stream(line);
        std::string date, value;

        if (std::getline(stream, date, ',') && std::getline(stream, value))
        {
            if (isValidDate(date) && isValidValue(value))
                data[date] = std::atof(value.c_str());
        }
    }
    file.close();
}

void BitcoinExchange::processInput(const std::string &filename) const
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open input file." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream stream(line);
        std::string date, value;
        if (std::getline(stream, date, '|') && std::getline(stream, value))
        {
            date.erase(std::remove(date.begin(), date.end(), ' '), date.end());
            value.erase(std::remove(value.begin(), value.end(), ' '), value.end());

            if (!isValidDate(date))
            {
                std::cerr << "Error: Invalid date => " << date << std::endl;
            }
            else if (!isValidValue(value))
            {
                std::cerr << "Error: Invalid value => " << value << std::endl;
            }
            else
            {
                double rate = findClosestDate(date);
                double amount = std::atof(value.c_str());
                std::cout << date << " => " << value << " = " << amount * rate << std::endl;
            }
        }
        else
        {
            std::cerr << "Error: Invalid line format => " << line << std::endl;
        }
    }
    file.close();
}

double BitcoinExchange::findClosestDate(const std::string &date) const
{
    std::map<std::string, double>::const_iterator it = data.lower_bound(date);
    if (it == data.end() || it->first != date)
    {
        if (it == data.begin())
            throw std::runtime_error("Error: No earlier date found.");
        --it;
    }
    return it->second;
}

bool BitcoinExchange::isValidDate(const std::string &date) const
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return (false);

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (year < 2000 || year > 2100 || month < 1 || month > 12 || day < 1 || day > 31)
        return (false);

    return (true);
}

bool BitcoinExchange::isValidValue(const std::string &value) const
{
    double val = std::atof(value.c_str());
    return (val >= 0.0 && val <= 1000.0);
}
