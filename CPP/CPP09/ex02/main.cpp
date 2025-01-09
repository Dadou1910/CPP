#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Error: Please provide a sequence of positive integers as arguments." << std::endl;
        return 1;
    }

    try
    {
        PmergeMe pmerge;
        pmerge.loadSequence(argv);
        pmerge.processSequences();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}


