#include <bits/stdc++.h>
namespace hcd
{


    class Input
    {
    public:
        void read(std::string fileName);
        Input();
        Input(const Input &input);
    };

    class Output
    {
    public:
        Input input;
        std::string outputFile;

    public:
        Output(Input &input, std::string fileName);
        Output();
        Output(const Output &output);

        // called in the constructor
        void generateOutput();

        void write(std::string fileName);
    };

    class Evaluator
    {
    public:
        Evaluator(std::string fileName);
        Evaluator(Evaluator &&) = default;
        void compute(Input &input, Output *output);
        void write(std::string fileName);

    private:
        long long process(Input &input, Output *output);

    public:
        Output *_bestOutput = nullptr;
        long long _bestCurrentScore = 0;
        long long _bestGlobalScore = 0;
        std::string _bestScorePath;
        std::unique_ptr<std::mutex> _mutex = std::make_unique<std::mutex>();
    };
}; // namespace hcd