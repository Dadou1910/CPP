#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cstdlib>
#include <algorithm>

class BitcoinExchange
{
private:
    std::map<std::string, double> data;

    bool isValidDate(const std::string &date) const;
    bool isValidValue(const std::string &value) const;
    double findClosestDate(const std::string &date) const;

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    void loadDatabase(const std::string &filename);
    void processInput(const std::string &filename) const;
};

#endif