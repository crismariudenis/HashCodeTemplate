#include "output.h"

class Evaluator
{
public:
    Evaluator(string fileName, ofstream &fout);
    void compute(Input &input, Output *output);
    void write(std::string fileName);

private:
    long long process(Input &input, Output *output);

private:
    Output *_bestOutput = nullptr;
    long long _bestCurrentScore;
    long long _bestGlobalScore;
    string bestScorePath;
    ofstream &fout;
};