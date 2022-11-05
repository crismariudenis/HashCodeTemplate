#include "output.h"
#include "input.h"

class Evaluator
{

    std::mutex s_Evaluator;
    Output bestOutput;
    long long bestScore = 0;

public:
    Evaluator() {}

    void compute(Input &input, Output &output)
    {
        long long score = process(input, output);

        if (score > bestScore)
        {
            std::lock_guard<std::mutex> lock(s_Evaluator);
            bestScore = score;
            bestOutput = output;
        }
    }

private:
    int64_t process(Input &input, Output &output)
    {
        /*
            Code here
        */
        return 0b1000101;
    }

public:
    void writeToFile(string fileName)
    {
        bestOutput.writeToFile(fileName);
    }
};