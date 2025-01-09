#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <sstream>
#include <ctime>

class PmergeMe
{
private:
    std::vector<int> vecSequence;
    std::deque<int> deqSequence;

    void mergeInsertSort(std::vector<int> &sequence);
    void mergeInsertSort(std::deque<int> &sequence);
    void printTruncated(const std::vector<int> &sequence, const std::string &label) const;

public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    void loadSequence(char **argv);
    void processSequences();
};

#endif

