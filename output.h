#include "input.h"

class Output
{
public:
    Input input;
    Output(Input input, std::ofstream &f);

    void generateOutput();

    void write(std::string fileName);

    // read the previous output from the file
    void read(std::string fileName);

    std::ofstream &f;
};