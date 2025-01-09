#include "FileProcessor.hpp"

FileProcessor::FileProcessor(const std::string& inputFile, const std::string& s1, const std::string& s2)
    : InputFileName(inputFile), OutputFileName(inputFile + ".replace"), S1(s1), S2(s2) {}

std::string FileProcessor::replaceOccurrences(const std::string& line, const std::string& s1, const std::string& s2)
{
    std::string result;          // Store the modified string
    size_t start = 0;            // Start position for finding s1
    size_t pos;                  // Position of the found substring

    while ((pos = line.find(s1, start)) != std::string::npos) // Find all occurrences of s1
    {
        result += line.substr(start, pos - start); // Add text before the match
        result += s2;                             // Replace with s2
        start = pos + s1.length();                 // Move past the match
    }

    result += line.substr(start); // Add the rest of the line
    return result;
}

void FileProcessor::processFile()
{
    std::ifstream inputFile(InputFileName.c_str());
    if (!inputFile.is_open())
    {
        std::cerr << "Error: Could not open file " << InputFileName << std::endl;
        return;
    }
    std::ofstream outputFile(OutputFileName.c_str());
    if (!outputFile.is_open())
    {
        std::cerr << "Error: Could not create file " << OutputFileName << std::endl;
        return;
    }
    std::string line;
    while (std::getline(inputFile, line))
    {
        outputFile << replaceOccurrences(line, S1, S2) << std::endl;
    }
    inputFile.close();
    outputFile.close();
    std::cout << "File processing complete. Output written to: " << OutputFileName << std::endl;
}
