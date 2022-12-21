#include "evaluator.h"
#include "utils/timer.h"
#include "utils/config.h"

Input input;
vector<Output *> outputs;

void solve(Output *output, Evaluator &evaluator)
{
    evaluator.compute(input, output);
}

int main()
{
    input.read(inputFile);

    outputs.resize(nrOutputs);

    Evaluator evaluator;

    for (int i = 0; i < nrLoops; i++)
        solve(outputs[i], evaluator);

    evaluator.write(outputFile);
}
