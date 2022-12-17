#include "input.h"
#include "output.h"

class Evaluator
{
public:
    Evaluator(Output &output) : _bestOutput(output) {}
    void compute(Input &input, Output &output);
    void write(std::string fileName);

private:
    long long process(Input &input, Output &output);

private:
    Output &_bestOutput;
    long long _bestCurrentScore;
    long long _bestGlobalScore;
};