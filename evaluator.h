#include "input.h"
#include "output.h"

class Evaluator
{
public:
    Evaluator(Output &output) : _bestOutput(output)
    {
        // Todo: read the previous best score from the file
    }
    void compute(Input &input, Output &output)
    {
        long long score = process(input, output);
        assert(score >= 0);
        if (score > _bestCurrentScore)
        {
            _bestCurrentScore = score;
            _bestOutput = output;
        }
    }

    void write(std::string fileName)
    {
        if (_bestCurrentScore > _bestGlobalScore)
        {
            // Todo: write the best score to the file
            _bestOutput.write(fileName);
        }
    }

private:
    long long process(Input &input, Output &output);

private:
    Output &_bestOutput;
    long long _bestCurrentScore;
    long long _bestGlobalScore;
};