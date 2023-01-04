#include "output.h"

class Evaluator
{
public:
    Evaluator(string fileName);
    void compute(Input &input, Output *output);
    void write(std::string fileName);

private:
    long long process(Input &input, Output *output);

public:
    Output *_bestOutput = nullptr;
    long long _bestCurrentScore = 0;
    long long _bestGlobalScore = 0;
    string bestScorePath;
};