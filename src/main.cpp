#include "evaluator.h"
#include "../utils/timer.h"
#include "../utils/config.h"

vector<Evaluator> evaluators;
int main()
{
    evaluators.reserve(5);
    for (int index = 0; index < 5; ++index)
    {
        ifstream fin(bestScoreFile[index]);
        if (isEmpty(fin))
        {
            ofstream fout(bestScoreFile[index]);
            fout << 0;
        }
        evaluators.emplace_back(Evaluator(bestScoreFile[index]));
    }
    for (int test = 0; test < 5; ++test)
    {
        std::cout << "\nTest " << char('A' + test) << " started!\n";
        Timer timer{"Total"};

        Input input;

        input.read(inputFile[test]);

        vector<Output> outputs;
        outputs.reserve(nrOutputs);

        for (int i = 0; i < nrOutputs; ++i)
        {
            outputs.emplace_back(Output(input, outputFile[test]));
            evaluators[test].compute(input, &outputs[i]);
        }

        evaluators[test].write(outputFile[test]);
    }
}
