#include "evaluator.h"
#include "utils/timer.h"
#include "utils/config.h"

vector<Output> outputs;

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

    for (int test = 0; test < 6; ++test)
    {
        cout << "\n\n";
        std::cout << "Test " << char('A' + test) << " started!\n";
        Timer timer{"Total"};

        Input input;

        input.read(inputFile[test]);

        outputs.clear();

        Evaluator evaluator(bestScoreFile[test]);

        for (int i = 0; i < nrOutputs; ++i)
        {
            cout << i + 1 << " iteration\n";
            outputs.push_back(Output(input));
            evaluator.compute(input, &outputs[i]);
            cout << "\n";
        }

        evaluator.write(outputFile[test]);
    }
}
