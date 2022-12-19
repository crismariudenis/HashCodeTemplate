#include "input.h"

class Output
{
public:
    Output() { generateOutput(); }

    void generateOutput();

    void write(std::string fileName);

    // read the previous output from the file
    void read(std::string fileName);
};