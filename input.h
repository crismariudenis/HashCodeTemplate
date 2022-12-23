#include "utils/bits.h"

using namespace std;
struct Client
{
    map<string, bool> likes;
    map<string, bool> dislikes;
};

class Input
{
    vector<Client> clients;
    set<string> ingredients;

public:
    void read(string fileName);
    /*
        More functions wiil appear depending on the problem
    */
};