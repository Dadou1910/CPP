#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <limits>

class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter &operator=(const ScalarConverter &other);
    ~ScalarConverter();

    static bool isChar(const std::string &input);
    static bool isInt(const std::string &input);
    static bool isFloat(const std::string &input);
    static bool isDouble(const std::string &input);

    static void convertChar(const std::string &input);
    static void convertInt(const std::string &input);
    static void convertFloat(const std::string &input);
    static void convertDouble(const std::string &input);
    static void convertSpecialFloat(const std::string &input);
    static void convertSpecialDouble(const std::string &input);

public:
    static void convert(const std::string &input);
};

#endif
