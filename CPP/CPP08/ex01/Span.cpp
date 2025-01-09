#include "Span.hpp"

Span::Span(unsigned int n) : maxSize(n) {}

Span::Span(const Span &other) : maxSize(other.maxSize), numbers(other.numbers) {}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        maxSize = other.maxSize;
        numbers = other.numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number)
{
    if (numbers.size() >= maxSize)
        throw std::runtime_error("Cannot add more numbers: Span is full.");
    numbers.push_back(number);
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (numbers.size() + std::distance(begin, end) > maxSize)
        throw std::runtime_error("Cannot add more numbers: Exceeds span capacity.");
    numbers.insert(numbers.end(), begin, end);
}

int Span::shortestSpan() const
{
    if (numbers.size() < 2)
        throw std::runtime_error("Not enough numbers to calculate span.");

    std::vector<int> sorted = numbers;
    std::sort(sorted.begin(), sorted.end());

    int minSpan = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sorted.size(); ++i)
        minSpan = std::min(minSpan, sorted[i] - sorted[i - 1]);

    return minSpan;
}

int Span::longestSpan() const
{
    if (numbers.size() < 2)
        throw std::runtime_error("Not enough numbers to calculate span.");

    int minVal = *std::min_element(numbers.begin(), numbers.end());
    int maxVal = *std::max_element(numbers.begin(), numbers.end());

    return maxVal - minVal;
}

void Span::printNumbers() const
{
    std::cout << "Numbers in Span: ";
    for (size_t i = 0; i < numbers.size(); ++i)
        std::cout << numbers[i] << " ";
    std::cout << std::endl;
}
