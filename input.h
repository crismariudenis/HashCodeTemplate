#include "utils/bits.h"
#include "utils/config.h"

using namespace std;
struct Client
{
    map<string, bool> likes;
    map<string, bool> dislikes;
};

class Input
{

public:
    vector<Client> clients;
    set<string> ingredients;

    void read(string fileName);
};