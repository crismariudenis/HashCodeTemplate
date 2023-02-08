#ifndef H_OUTPUT
#define H_OUTPUT


#include "input.h"


class Output
{
public:
    Input input;
    std::string outputFile;

public:
    Output(Input &input, std::string fileName);
    Output();
    Output(const Output & output);

    // called in the constructor
    void generateOutput();

    void write(std::string fileName);
};


#endif // H_OUTPUT