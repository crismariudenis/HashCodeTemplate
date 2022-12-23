#include "input.h"

class Output
{
public:
    Input input;
    std::set<string> answer ;
    std::string outputFile;

    void setInput(Input input);

    void setOutputFile(string outputFIle);

    void generateOutput();

    void write(std::string fileName);

    // read the previous output from the file
    void read(std::string fileName);
};