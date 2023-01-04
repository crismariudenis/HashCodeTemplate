#include "evaluator.h"
#include "utils/timer.h"
#include "utils/config.h"

vector<Output> outputs;

void solve(Output *output, Evaluator &evaluator, Input &input)
{
    evaluator.compute(input, output);
}

int main()
{
    for (int index = 0; index < 5; ++index)
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
        cout << '\n';
        std::cout << "Test " << char('A' + test) << " started!\n";
        Timer timer;

        Input input;

        input.read(inputFile[test]);
        outputs.clear();
        for (int i = 0; i < nrOutputs; ++i)
            outputs.push_back(Output());
            
        for (int i = 0; i < nrOutputs; ++i)
        {
            outputs[i].setInput(input);
            outputs[i].setOutputFile(outputFile[test]);

            outputs[i].generateOutput();
        }

        Evaluator evaluator(bestScoreFile[test]);

        for (int i = 0; i < nrOutputs; i++)
            solve(&outputs[i], evaluator, input);

        evaluator.write(outputFile[test]);
    }
}