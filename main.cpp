#include "evaluator.h"
#include "utils/timer.h"


void singleThread();
void multiThread();

//-----------Global values-----------
const int nrLoops = 100;
const string inputFile = "in.txt";
const string outputFile = "out.txt";
//------------------------------------

Evaluator evaluator;
Input input;

void solve()
{
    Output output;
    evaluator.compute(input, output);
}

int main()
{
    input.readFromFile(inputFile);
    singleThread();
    evaluator.writeToFile(outputFile);
}
void multiThread()
{
    std::vector<std::future<void>> futures;

    for (int i = 1; i <= nrLoops; i++)
        futures.push_back(std::async(std::launch::async, solve));
}
void singleThread()
{
    for (int i = 1; i <= nrLoops; i++)
        solve();
}
