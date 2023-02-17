#include "hcd.h"
#include "../utils/timer.h"

namespace hcd
{

    Evaluator::Evaluator(std::string fileName) : _bestScorePath(fileName)
    {
        std::ifstream fin(fileName);
        fin >> _bestGlobalScore;
    }
    long long Evaluator::process(Input &input, Output *output)
    {
        /*
            Code here
        */
        return 0b0000001;
    }
    void Evaluator::write(std::string fileName)
    {
        if (_bestCurrentScore > _bestGlobalScore)
        {
            std::ofstream fout(_bestScorePath);
            fout << _bestCurrentScore;
            _bestOutput->write(fileName);
            char test = std::toupper(_bestScorePath[_bestScorePath.size() - 5]);
            std::cout << "\033[1;31mNew best for test " << test << " (" << _bestCurrentScore << " pts)!"
                      << "\n\033[0m";
        }
    }
    void Evaluator::compute(Input &input, Output *output)
    {
        long long score = process(input, output);
        assert(score >= 0);

        std::lock_guard<std::mutex> lock(*_mutex.get());
        if (score > _bestCurrentScore)
        {
            _bestCurrentScore = score;
            _bestOutput = output;
        }
    }
}