#include "evaluator.h"

Evaluator::Evaluator(string fileName)
{
    ifstream fin(fileName);
    fin >> _bestGlobalScore;
    _bestCurrentScore = 0;
    bestScorePath = fileName;
    // std::cout << _bestGlobalScore << '\n';
}

long long Evaluator::process(Input &input, Output *output)
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
        ofstream fout(bestScorePath);
        fout << _bestCurrentScore;
        _bestOutput->write(fileName);
        std::cout << "New best output for test " << (char)(std::toupper(bestScorePath[17])) << '!' << '\n';
    }
}
void Evaluator::compute(Input &input, Output *output)
{
    long long score = process(input, output);
    assert(score >= 0);
    if (score > _bestCurrentScore)
    {
        _bestCurrentScore = score;
        _bestOutput = output;
    }
}