#include "bits.h"

const int nrOutputs = 10;
const std::vector<std::string> inputFile = {"utils/inputs/a.txt",
                                            "utils/inputs/b.txt",
                                            "utils/inputs/c.txt",
                                            "utils/inputs/d.txt",
                                            "utils/inputs/e.txt",
                                            "utils/inputs/f.txt"};

const std::vector<std::string> outputFile = {"utils/outputs/a.txt",
                                             "utils/outputs/b.txt",
                                             "utils/outputs/c.txt",
                                             "utils/outputs/d.txt",
                                             "utils/outputs/e.txt",
                                             "utils/outputs/f.txt"};

const std::vector<std::string> bestScoreFile = {"utils/bestScores/a.txt",
                                                "utils/bestScores/b.txt",
                                                "utils/bestScores/c.txt",
                                                "utils/bestScores/d.txt",
                                                "utils/bestScores/e.txt",
                                                "utils/bestScores/f.txt"};

bool isEmpty(ifstream &fin)
{
    std::string str;
    getline(fin, str);
    return str.size() == 0;
}