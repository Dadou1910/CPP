#include "Fixed.hpp"

// Constructors and Destructor
Fixed::Fixed() : Value(0) {}
Fixed::Fixed(const int value) { Value = value << FractionalBits; }
Fixed::Fixed(const float value) { Value = roundf(value * (1 << FractionalBits)); }
Fixed::Fixed(const Fixed &other) { *this = other; }
Fixed::~Fixed() {}

// Assignment operator
Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other)
        Value = other.Value;
    return *this;
}

// Comparison operators
bool Fixed::operator>(const Fixed &other) const { return Value > other.Value; }
bool Fixed::operator<(const Fixed &other) const { return Value < other.Value; }
bool Fixed::operator>=(const Fixed &other) const { return Value >= other.Value; }
bool Fixed::operator<=(const Fixed &other) const { return Value <= other.Value; }
bool Fixed::operator==(const Fixed &other) const { return Value == other.Value; }
bool Fixed::operator!=(const Fixed &other) const { return Value != other.Value; }

// Arithmetic operators
Fixed Fixed::operator+(const Fixed &other) const { return Fixed(toFloat() + other.toFloat()); }
Fixed Fixed::operator-(const Fixed &other) const { return Fixed(toFloat() - other.toFloat()); }
Fixed Fixed::operator*(const Fixed &other) const { return Fixed(toFloat() * other.toFloat()); }
Fixed Fixed::operator/(const Fixed &other) const
{
    if (other.Value == 0) {
        std::cerr << "Division by zero!" << std::endl;
        return Fixed(0);
    }
    return Fixed(toFloat() / other.toFloat());
}

// Increment and Decrement operators
Fixed &Fixed::operator++() { ++Value; return *this; }
Fixed Fixed::operator++(int) { Fixed temp(*this); ++Value; return temp; }
Fixed &Fixed::operator--() { --Value; return *this; }
Fixed Fixed::operator--(int) { Fixed temp(*this); --Value; return temp; }

// Static min and max functions
Fixed &Fixed::min(Fixed &a, Fixed &b) { return (a < b) ? a : b; }
const Fixed &Fixed::min(const Fixed &a, const Fixed &b) { return (a < b) ? a : b; }
Fixed &Fixed::max(Fixed &a, Fixed &b) { return (a > b) ? a : b; }
const Fixed &Fixed::max(const Fixed &a, const Fixed &b) { return (a > b) ? a : b; }

// Conversion functions
float Fixed::toFloat(void) const { return (float)Value / (1 << FractionalBits); }
int Fixed::toInt(void) const { return Value >> FractionalBits; }

// Getter and Setter
int Fixed::getRawBits(void) const { return Value; }
void Fixed::setRawBits(int const raw) { Value = raw; }

// Stream insertion operator
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}

