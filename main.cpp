#include "evaluator.h"
#include "utils/timer.h"
#include "utils/config.h"

Input input;
vector<Output> outputs;
Evaluator evaluator;

void solve(Output &output)
{
    evaluator.compute(input, output);
}

int main()
{
    input.read(inputFile);

    // generate the initial outputs

    //Todo: initialize the outputs by using the input
     
    for (int i = 0; i < nrOutputs; i++)
        outputs.emplace_back(Output{});

      
    for (int i = 0; i < nrLoops; i++)
        solve(outputs[i]);

    evaluator.write(outputFile);
}
