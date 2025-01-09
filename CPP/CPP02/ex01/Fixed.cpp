#include "Fixed.hpp"

Fixed::Fixed() : Value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const value)
{
    std::cout << "Int constructor called" << std::endl;
    Value = value << FractionalBits;
}

Fixed::Fixed(float const value)
{
    std::cout << "Float constructor called" << std::endl;
    Value = (value * (1 << FractionalBits)) + (value >= 0 ? 0.5f : -0.5f);
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

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
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

float Fixed::toFloat(void) const
{
    return ((float)Value / (1 << FractionalBits));
}

int Fixed::toInt(void) const
{
    return (Value >> FractionalBits);
}

