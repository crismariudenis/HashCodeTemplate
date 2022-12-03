#include "evaluator.h"
#include "timer.h"

using namespace std;

//-----------Global values-----------
const int nrLoops = 100;
const string inputFileName = "in.txt";
const string outputFileName = "out.txt";
//------------------------------------

Evaluator evaluator;
Input input;

void solve()
{
    Output output;
    /*
     *  Generate output here
     */
    evaluator.compute(input, output);
}
signed main()
{

    input.readFromFile(inputFileName);

    std::vector<std::future<void>> futures;

    for (int i = 0; i < nrLoops; i++)
        futures.push_back(std::async(std::launch::async, solve));

    // Write the best output to the file
    evaluator.writeToFile(outputFileName);
}
