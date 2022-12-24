#include "output.h"
#include "utils/timer.h"
struct element
{
    int likes, dislikes;
    string ingredient;
    double raport;
};

bool cmp(element a, element b)
{
    if (a.raport != b.raport)
        return a.raport < b.raport;
    if (a.likes != b.likes)
        return a.likes < b.likes;
    return a.dislikes > b.dislikes;
}

void Output::generateOutput()
{
    Timer timer{"generateOutput"};
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
    map<string, bool> banList;
    for (auto i : ingredients)
    {
        if (dislikes[i] > likes[i])
        {
            banList[i] = 1;
            continue;
        }
        // std::cout << likes[i] << ' ' << dislikes[i] << '\n';
        int r = dislikes[i];
        if (!r)
        {
            precIngredients.push_back({likes[i], dislikes[i], i, 1e9});
            continue;
        }
        double raport = (double)(likes[i]) / (double)(r);
        precIngredients.push_back({likes[i], dislikes[i], i, raport});
    }

    map<int, bool> civilianBanList;

    int cnt = 0;
    while (1)
    {
        if (precIngredients.size() == 0)
            break;
        cnt++;
        // cout << precIngredients.size() << endl;
        sort(precIngredients.begin(), precIngredients.end(), cmp);
        //     for(int i = 0;i < precIngredients.size(); ++i)
        //     cout << setprecision(2) << fixed << precIngredients[i].raport << ' ';
        // cout << '\n';
        if (precIngredients[precIngredients.size() - 1].raport == 0)
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
        bool ok = 1;
        if (badClients.size() >= likes[currIngr])
            banList[currIngr] = 1;
        else
        {
            answer.insert(currIngr);
            for (auto i : badClients)
            {
                for (auto j : clients[i].likes)
                    likes[j.first]--;
                for (auto j : clients[i].dislikes)
                    dislikes[j.first]--;
            }
        }
        for (auto i : ingredients)
        {
            if (banList[i])
                continue;
            if (dislikes[i] > likes[i])
            {
                banList[i] = 1;
                continue;
            }
            int r = dislikes[i];
            if (!r)
            {
                precIngredients.push_back({likes[i], dislikes[i], i, 1e9});
                continue;
            }
            double raport = (double)(likes[i]) / (double)(r);
            precIngredients.push_back({likes[i], dislikes[i], i, raport});
        }
    }
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