#include "evaluator.h"
#include "utils/timer.h"
#include "utils/config.h"

Input input;
vector<Output> outputs;

// void solve(Output &output)
// {
//     evaluator.compute(input, output);
// }

int main()
{
    input.read(inputFile);

    // generate the initial outputs

    // Todo: initialize the outputs by using the input

    for (int i = 0; i < nrOutputs; i++)
        outputs.emplace_back(Output{});

    Evaluator evaluator(outputs[1]);

    // for (int i = 0; i < nrLoops; i++)
    //     solve(outputs[i]);

    evaluator.write(outputFile);
}
