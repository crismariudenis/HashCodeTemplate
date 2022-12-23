#include "output.h"

struct element
{
    int likes, dislikes;
    string ingredient;
    double raport;
};

bool cmp(element a, element b)
{
    return a.raport < b.raport;
}

void Output::generateOutput()
{
    std::vector<Client> clients = input.clients;
    std::vector<element> precIngredients;
    std::set<string> ingredients = input.ingredients;
    std::map<string, int> likes, dislikes;
    for (auto i : ingredients)
    {
        for (int j = 0; j < clients.size(); ++j)
        {
            likes[i] += clients[j].likes[i];
            dislikes[i] += clients[j].dislikes[i];
        }
    }
    for (auto i : ingredients)
    {
        // std::cout << likes[i] << ' ' << dislikes[i] << '\n';
        int r = dislikes[i];
        if (!r)
            r = 1;
        double raport = (double)(likes[i]) / (double)(r);
        precIngredients.push_back({likes[i], dislikes[i], i, raport});
    }
    map<string, bool> banList;
    map<int, bool> civilianBanList;
    int cnt = 0;
    while (1)
    {

        cnt++;
        cout<<precIngredients.size()<<endl;
        sort(precIngredients.begin(), precIngredients.end(), cmp);
  
        if (precIngredients[precIngredients.size() - 1].raport == 0)
            break;

        answer.insert(precIngredients.back().ingredient);
        if (precIngredients.size() == 1)
            break;
        std::set<int> badClients;

        element currentBest = precIngredients.back();
        precIngredients.clear();
        string currIngr = currentBest.ingredient;
        banList[currentBest.ingredient] = 1;
        std::map<int, bool> nr;

        for (int i = 0; i < clients.size(); ++i)
        {
            if (civilianBanList[i])
                continue;
            if (clients[i].dislikes[currIngr])
                badClients.insert(i), nr[i] = civilianBanList[i] = 1;
        }
        // cout << currIngr << ' ' << currentBest.raport << '\n';
        for (auto i : badClients)
        {
            for (auto j : clients[i].likes)
            {
                if (j.first == currIngr)
                    likes[j.first]--;
            }
            for (auto j : clients[i].dislikes)
            {
                if (j.first == currIngr)
                    dislikes[j.first]--;
            }
        }
        for (auto i : ingredients)
        {
            if (banList[i])
                continue;
            int r = dislikes[i];
            if (!r)
                r = 1;
            double raport = (double)(likes[i]) / (double)(r);
            precIngredients.push_back({likes[i], dislikes[i], i, raport});
        }
    }

    this->write(outputFile);
}
void Output::write(std::string fileName)
{

    ofstream fout(outputFile);
    fout << answer.size() << ' ';
    for (auto i : answer)
        fout << i << ' ';
}
void Output::read(std::string fileName)
{
    /*
        Code here
    */
}
void Output::setInput(Input x)
{
    input = x;
}
void Output::setOutputFile(string outputFile)
{
    this->outputFile = outputFile;
}