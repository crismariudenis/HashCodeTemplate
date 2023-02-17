#include "hcd.h"
#include "../utils/timer.h"

namespace hcd
{
    Output::Output() {}
    Output::Output(const Output &output){};
    Output::Output(Input &input, std::string fileName) : input(input), outputFile(fileName)
    {
        generateOutput();
    }
    void Output::generateOutput()
    {
        /*
            Code here
        */
    }
    void Output::write(std::string fileName)
    {
        /*
            Code here
        */
    }

}