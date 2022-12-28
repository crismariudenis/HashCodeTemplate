#include "evaluator.h"
#include "utils/timer.h"
Evaluator::Evaluator(string fileName, std::ofstream &fout):bestScorePath(fileName),_bestCurrentScore(0), fout(fout)
{
    ifstream fin(fileName);
    fin >> _bestGlobalScore;
}

long long Evaluator::process(Input &input, Output *output)
{
    Timer timer{fout, "process"};
    /*
        Code here
    */
    return 0b0000000;
}
void Evaluator::write(std::string fileName)
{
    if (_bestCurrentScore > _bestGlobalScore)
    {
        ofstream fout(bestScorePath);
        fout << _bestCurrentScore;
        _bestOutput->write(fileName);
        std::cout << "\033[1;31mNew best output for test " << (char)(std::toupper(bestScorePath[bestScorePath.size() - 5])) << '!' << "\n\033[0m";
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