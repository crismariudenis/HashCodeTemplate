#include "evaluator.h"
#include "output.h"

Evaluator::Evaluator(Output &output) : _bestOutput(output)
{
    ifstream fin("utils/bestScore.txt");
    int score;
    fin >> score;
    _bestGlobalScore = score;
    _bestCurrentScore = 0;
    std::cout << _bestGlobalScore << '\n';
}

long long Evaluator::process(Input &input, Output &output)
{
    /*
        Code here
    */
    return 0b1000101;
}
void Evaluator::write(std::string fileName)
{
    if (_bestCurrentScore > _bestGlobalScore)
    {
        ofstream fout("utils/bestScore.txt");
        fout << _bestCurrentScore;
        _bestOutput.write(fileName);
    }
}
void Evaluator::compute(Input &input, Output &output)
{
    long long score = process(input, output);
    assert(score >= 0);
    if (score > _bestCurrentScore)
    {
        _bestCurrentScore = score;
        _bestOutput = output;
    }
}