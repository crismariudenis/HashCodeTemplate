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
        Timer timer;

        Input input;

        input.read(inputFile[test]);

        outputs.clear();

        Evaluator evaluator(bestScoreFile[test]);

        for (int i = 0; i < nrOutputs; ++i){
            cout << i + 1 << " iteration\n";
            outputs.push_back(Output(input));
            solve(&outputs[i], evaluator, input);    
            cout << "\n";
        }  
        

        evaluator.write(outputFile[test]);
    }
}
