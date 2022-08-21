#include <bits/stdc++.h>
#include "evaluator.h"

using namespace std;

//-----------General values-----------
const int nrLoops = 10;
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
    // This runs the program nrLoops
    for (int i = 1; i <= nrLoops; i++)
        solve();
}