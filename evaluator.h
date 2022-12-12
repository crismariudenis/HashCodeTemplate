#include "output.h"
#include "input.h"

class Evaluator
{

public:
    void compute(Input &input, Output &output)
    {
        long long score = process(input, output);

        if (score > _bestScore)
        {
            std::lock_guard<std::mutex> lock(s_Evaluator);
            _bestScore = score;
            _bestOutput = output;
        }
    }

    void writeToFile(std::string fileName)
    {
        _bestOutput.writeToFile(fileName);
    }

private:
    long long process(Input &input, Output &output);

private:
    std::mutex s_Evaluator;
    Output _bestOutput;
    long long _bestScore = 0;
};