#include "Fixed.hpp"

Fixed::Fixed() : Value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    *this = other;
    std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;

    if (this != &other)
        this->Value = other.Value;
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void )
{
    std::cout << "getRawBits function called" << std::endl;
    return (Value);
}

void Fixed::setRawBits(int const raw)
{
    Value = raw;
    std::cout << "setRawBits member function called" << std::endl;
}
