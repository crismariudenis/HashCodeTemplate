#include <bits/stdc++.h>
#include "evaluator.h"

using namespace std;

//-----------General values-----------
const int nrLoops = 10;
const int nrTreads = 4;
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
    // Read the input
    input.read();

    // Every thread will run nrLoops times the solve function
    vector<thread> threads(nrTreads);

    for (int i = 0; i < nrLoops; i++)
    {
        for (int j = 0; j < nrTreads; j++)
            threads[j] = thread(solve);
        for (int j = 0; j < nrTreads; j++)
            threads[j].join();
    }

    // Write the best output to the file
    evaluator.bestOutput.writeToFile(outputFileName);
}