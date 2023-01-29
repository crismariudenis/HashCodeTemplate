
#include "output.h"

class Evaluator
{
public:
    Evaluator(string fileName);
    Evaluator(Evaluator &&) = default;
    void compute(Input &input, Output *output);
    void write(std::string fileName);

private:
    long long process(Input &input, Output *output);

public:
    Output *_bestOutput = nullptr;
    long long _bestCurrentScore = 0;
    long long _bestGlobalScore = 0;
    string _bestScorePath;
    std::unique_ptr<std::mutex> _mutex = std::make_unique<std::mutex>();
};