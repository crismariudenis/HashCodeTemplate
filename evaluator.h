#include "output.h"
#include "input.h"
class Evaluator
{
public:
    Output bestOutput;
    long long bestScore = 0;
    Evaluator()
    {
    }
    /**
     * @brief Calls the process for getting the score and updates the best values
     *
     * @param input the input of the problem
     * @param output the output generated
     */
    void compute(Input &input, Output &output)
    {
        long long score = process(input, output);

        if (score > bestScore)
        {
            score = bestScore;
            bestOutput = output;
        }
        
    }
    long long process(Input &input, Output &output)
    {
        /*
            Code here
        */
        return 69;
    }
};