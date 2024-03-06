#include <algorithm>   // for std::copy
#include <cstdlib>     // for EXIT_FAILURE
#include <fstream>     // for std::filebuf
#include <iterator>    // for std::{i,o}streambuf_iterator

int main(int argc, char *argv[])
{
    if (argc != 3) return EXIT_FAILURE; // To make program take two files during runtime

    std::filebuf inputFile, outputFile; // Initializing two file bufers for copying
    inputFile.open(argv[1], std::ios::in | std::ios::binary); // Starting input file buffer
    outputFile.open(argv[2], std::ios::out | std::ios::binary); // Starting output file buffer

    std::copy(std::istreambuf_iterator<char>(&inputFile), {},
              std::ostreambuf_iterator<char>(&outputFile)); 
    // opening the input file into buffer 
    // copying the input buffer to the outputbuffer.
    return 0;
}
