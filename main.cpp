#include "evaluator.h"
#include "utils/timer.h"
#include "utils/config.h"
vector<Output> outputs;
vector<Evaluator> evaluators;
void solve(Output *output, Evaluator &evaluator, Input &input)
{
    output->generateOutput();
    evaluator.compute(input, output);
}
void solve2(Output *output, Evaluator &evaluator, Input &input)
{
    evaluator.compute(input, output);
}

int main()
{
    evaluators.reserve(nrOutputs);

    for (int index = 0; index < 5; ++index)
    {
        ifstream fin(bestScoreFile[index]);
        if (isEmpty(fin))
        {
            ofstream fout(bestScoreFile[index]);
            fout << 0;
        }
    }
    for (int test = 3; test < 4; ++test)
    {
        cout << '\n';
        std::cout << "Test " << char('A' + test) << " started!\n";
        Timer timer{"Total"};

        Input input;

        input.read(inputFile[test]);
        outputs.clear();
        for (int i = 0; i < nrOutputs; ++i)
            outputs.push_back(Output());

        evaluators.emplace_back(Evaluator(bestScoreFile[test]));
        std::vector<std::thread> threadPool;

        for(int i=0;i<nrOutputs;++i)
        {
            outputs[i].setInput(input);
            outputs[i].setOutputFile(outputFile[test]);
            // solve(&outputs[i],evaluators[i],input);
            outputs[i].generateOutput();
        }
        Evaluator evaluator(bestScoreFile[test]);

        for(int i=0;i<nrOutputs;++i)
            evaluators[test].compute(input,&outputs[i]);

         evaluators[test].write(outputFile[test]);

        // for (int i = 0; i < nrOutputs; ++i)
        //     threadPool.emplace_back(
        //         [i, test, &input]()
        //         {
        //             outputs[i].setInput(input);
        //             outputs[i].setOutputFile(outputFile[test]);
        //             solve(&outputs[i], evaluators[i], input);
        //         });
        // for (auto &a : threadPool)
        //     a.join();

    }
}