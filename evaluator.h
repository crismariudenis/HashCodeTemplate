#include "output.h"
#include "input.h"

class Evaluator
{

    std::mutex s_Evaluator;
    Output _bestOutput;
    long long _bestScore = 0;

public:
    Evaluator() {}

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

private:
    int64_t process(Input &input, Output &output);
    

public:
    void writeToFile(string fileName)
    {
        _bestOutput.writeToFile(fileName);
    }
};