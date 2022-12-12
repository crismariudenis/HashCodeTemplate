#include <iostream>

class Output
{
public:
    Output() { generateOutput(); }

    void generateOutput();

    void writeToFile(std::string fileName);
};