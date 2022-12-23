#include "evaluator.h"
#include "utils/timer.h"
#include "utils/config.h"

vector<Output> outputs;

void solve(Output* output, Evaluator &evaluator, Input &input)
{
    evaluator.compute(input, output);
}

int main()
{
    for (int index = 0; index < 6; ++index)
    {
        ifstream fin(bestScoreFile[index]);
        if (isEmpty(fin))
        {
            ofstream fout(bestScoreFile[index]);
            fout << 0;
        }
    }

    for (int test = 0; test < 5; ++test)
    {
        std::cout<<"Test "<<char('A'+test)<<" started!\n";
        Input input;


        input.read(inputFile[test]);

        outputs.clear();
        outputs.resize(nrOutputs); /// generating the outputs

        Evaluator evaluator(bestScoreFile[test]);


        for (int i = 0; i < nrOutputs; i++)
            solve(&outputs[i], evaluator, input);

        evaluator.write(outputFile[test]);
    }
}
