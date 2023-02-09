#ifndef H_INPUT
#define H_INPUT

#include "utils/bits.h"

using namespace std;

namespace hcd{


class Input
{
public:
    void read(string fileName);
    Input();
    Input(const Input & input);
};

}

#endif // H_INPUT