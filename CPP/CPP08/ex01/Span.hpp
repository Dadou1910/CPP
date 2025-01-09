#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <iostream>
#include <exception>
#include <iterator>
#include <limits>

class Span
{
private:
    unsigned int maxSize;
    std::vector<int> numbers;

public:
    Span(unsigned int n);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    void addNumber(int number);
    void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end); // Add range of numbers
    int shortestSpan() const;
    int longestSpan() const;

    void printNumbers() const; // For main
};

#endif

