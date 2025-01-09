#ifndef FILEPROCESSOR_HPP
#define FILEPROCESSOR_HPP

#include <iostream>
#include <string>
#include <fstream>

class FileProcessor
{
private:
    std::string InputFileName;
    std::string OutputFileName;
    std::string S1;
    std::string S2;

    // Helper method for string replacement
    std::string replaceOccurrences(const std::string& line, const std::string& s1, const std::string& s2);

public:
    // Constructor
    FileProcessor(const std::string& inputFile, const std::string& s1, const std::string& s2);

    // Processes the input file and writes the output
    void processFile();
};

#endif