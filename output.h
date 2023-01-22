#include "input.h"

class Output
{
public:
    Input input;
    std::string outputFile;

public:
    Output(Input &input, std::string fileName);
    Output();

    // called in the constructor
    void generateOutput();

    void write(std::string fileName);
};