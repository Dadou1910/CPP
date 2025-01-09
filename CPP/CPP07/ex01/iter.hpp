#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <cstdlib>

template <typename T, typename Func>
void iter(T *array, int length, Func function)
{
    if (!array || length <= 0)
    {
        std::cerr << "Error: Invalid input to iter function." << std::endl;
        std::exit(EXIT_FAILURE);
    }
    for (int i = 0; i < length; i++)
    {
        try
        {
            function(array[i]);
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error while applying function: " << e.what() << std::endl;
        }
        catch (...)
        {
            std::cerr << "Unknown error occurred." << std::endl;
        }
    }
}


#endif

