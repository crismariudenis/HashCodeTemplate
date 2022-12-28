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

    ofstream fout ("utils/logs.txt");

    for (int test = 0; test < 6; ++test)
    {
        fout << "\n";
        std::cout << "Test " << char('A' + test) << " started!\n";
        fout << "Test " << char('A' + test) << " started!\n\n";
        Timer timer(fout, "Total");

        Input input;

        input.read(inputFile[test]);

        outputs.clear();

        Evaluator evaluator(bestScoreFile[test], fout);

        for (int i = 0; i < nrOutputs; ++i)
        {

            fout << i + 1 << " iteration\n";
            outputs.push_back(Output(input, fout));
            evaluator.compute(input, &outputs[i]);
            fout << "\n";
        }

        evaluator.write(outputFile[test]);
    }
}
