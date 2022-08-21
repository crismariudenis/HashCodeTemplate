#include<bits/stdc++.h>
#include "evaluator.h"

using namespace std;
const int nrLoops = 1;

Evaluator evaluator;
Input input;
Output output;

int main(){
    cout<<evaluator.compute(input, output);
}