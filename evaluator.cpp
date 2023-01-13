#include "evaluator.h"
#include "utils/timer.h"
Evaluator::Evaluator(string fileName)
{
    ifstream fin(fileName);
    fin >> _bestGlobalScore;
    _bestCurrentScore = 0;
    bestScorePath = fileName;
}
long long Evaluator::process(Input &input, Output *output)
{
    long long ans = 0;
    int index = 0;
    for (auto client : input.clients)
    {
        long long ok = 1;

        for (auto ingredient : output->answer)
        {
            if (client.dislikes[ingredient])
            {
                ok = 0;
                break;
            }
        }

        for (auto likedIngredient : client.likes)
        {
            if (!output->answer.count(likedIngredient.first))
            {
                ok = 0;
                break;
            }
        }

        ans += ok;
        index++;
    }
    return ans;
}
void Evaluator::write(std::string fileName)
{
    if (_bestCurrentScore > _bestGlobalScore)
    {
        ofstream fout(bestScorePath);
        fout << _bestCurrentScore;
        _bestOutput->write(fileName);
        std::cout << "New best output for test " << (char)(std::toupper(bestScorePath[bestScorePath.size() - 5])) << '!' << endl;
    }
}
void Evaluator::compute(Input &input, Output *output)
{
    long long score = process(input, output);
    assert(score >= 0);
    // Todo: make this thread safe 
    if (score > _bestCurrentScore)
    {
        _bestCurrentScore = score;
        _bestOutput = output;
    }
}