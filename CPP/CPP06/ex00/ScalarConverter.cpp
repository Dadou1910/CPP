#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string &input)
{
    if (input == "nan" || input == "-inf" || input == "+inf")
        convertSpecialDouble(input);
    else if (input == "nanf" || input == "-inff" || input == "+inff")
        convertSpecialFloat(input);
    else if (isChar(input))
        convertChar(input);
    else if (isInt(input))
        convertInt(input);
    else if (isFloat(input))
        convertFloat(input);
    else if (isDouble(input))
        convertDouble(input);
    else
        std::cout << "Invalid input type." << std::endl;
}

bool ScalarConverter::isChar(const std::string &input)
{
    return input.length() == 1 && !isdigit(input[0]);
}

bool ScalarConverter::isInt(const std::string &input)
{
    char *end;
    std::strtol(input.c_str(), &end, 10);
    return *end == '\0';
}

bool ScalarConverter::isFloat(const std::string &input)
{
    char *end;
    std::strtof(input.c_str(), &end);
    return *end == 'f' && *(end + 1) == '\0';
}

bool ScalarConverter::isDouble(const std::string &input)
{
    char *end;
    std::strtod(input.c_str(), &end);
    return *end == '\0';
}

void ScalarConverter::convertChar(const std::string &input)
{
    char c = input[0];
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::convertInt(const std::string &input)
{
    int value = std::atoi(input.c_str());
    if (value >= 32 && value <= 126)
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << value << std::endl;
    std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
}

void ScalarConverter::convertFloat(const std::string &input)
{
    float value = std::strtof(input.c_str(), NULL);
    if (value >= 32 && value <= 126)
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(value) << std::endl;
    std::cout << "float: " << value << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void ScalarConverter::convertDouble(const std::string &input)
{
    double value = std::strtod(input.c_str(), NULL);
    if (value >= 32 && value <= 126)
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(value) << std::endl;
    std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
    std::cout << "double: " << value << std::endl;
}

void ScalarConverter::convertSpecialFloat(const std::string &input)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << input << std::endl;
    std::cout << "double: " << input.substr(0, input.length() - 1) << std::endl;
}

void ScalarConverter::convertSpecialDouble(const std::string &input)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << input << "f" << std::endl;
    std::cout << "double: " << input << std::endl;
}
