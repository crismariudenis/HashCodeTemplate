#include "output.h"
#include "utils/timer.h"

Output::Output(Input input, std::ofstream &fout) : fout(fout) 
{
    this->input = input;
    generateOutput();
}

void Output::generateOutput()
{   
    Timer timer{fout, "generateOutput"};
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
void Output::read(std::string fileName)
{
    /*
        Code here
    */
}
