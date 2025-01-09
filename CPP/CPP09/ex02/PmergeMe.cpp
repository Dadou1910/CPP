#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) : vecSequence(other.vecSequence), deqSequence(other.deqSequence) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        vecSequence = other.vecSequence;
        deqSequence = other.deqSequence;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::loadSequence(char **argv)
{
    for (int i = 1; argv[i] != NULL; ++i)
    {
        int number;
        std::istringstream iss(argv[i]);
        if (!(iss >> number) || number < 0)
        {
            throw std::invalid_argument("Error");
        }
        vecSequence.push_back(number);
        deqSequence.push_back(number);
    }
}

void PmergeMe::mergeInsertSort(std::vector<int> &sequence)
{
    if (sequence.size() <= 1)
        return;

    size_t mid = sequence.size() / 2;
    std::vector<int> left(sequence.begin(), sequence.begin() + mid);
    std::vector<int> right(sequence.begin() + mid, sequence.end());

    mergeInsertSort(left);
    mergeInsertSort(right);

    std::merge(left.begin(), left.end(), right.begin(), right.end(), sequence.begin());
}

void PmergeMe::mergeInsertSort(std::deque<int> &sequence)
{
    if (sequence.size() <= 1)
        return;

    size_t mid = sequence.size() / 2;
    std::deque<int> left(sequence.begin(), sequence.begin() + mid);
    std::deque<int> right(sequence.begin() + mid, sequence.end());

    mergeInsertSort(left);
    mergeInsertSort(right);

    std::merge(left.begin(), left.end(), right.begin(), right.end(), sequence.begin());
}

void PmergeMe::printTruncated(const std::vector<int> &sequence, const std::string &label) const
{
    std::cout << label;
    for (size_t i = 0; i < std::min(sequence.size(), size_t(5)); ++i)
    {
        std::cout << sequence[i] << " ";
    }
    if (sequence.size() > 5)
    {
        std::cout << "[...]";
    }
    std::cout << std::endl;
}

void PmergeMe::processSequences()
{
    std::cout << "Before: ";
    printTruncated(vecSequence, "");

    clock_t startVec = clock();
    mergeInsertSort(vecSequence);
    clock_t endVec = clock();

    clock_t startDeq = clock();
    mergeInsertSort(deqSequence);
    clock_t endDeq = clock();

    std::cout << "After: ";
    printTruncated(vecSequence, "");

    double vecTime = double(endVec - startVec) / CLOCKS_PER_SEC * 1000000;
    double deqTime = double(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000;

    std::cout << "Time to process a range of " << vecSequence.size()
              << " elements with std::vector : " << vecTime << " us" << std::endl;

    std::cout << "Time to process a range of " << deqSequence.size()
              << " elements with std::deque : " << deqTime << " us" << std::endl;
}


