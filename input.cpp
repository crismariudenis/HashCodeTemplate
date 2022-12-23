#include "input.h"

void Input::read(std::string fileName)
{
    ifstream cin(fileName);
    int nrClients;
    cin >> nrClients;
    clients.resize(nrClients);
    for (int i = 0; i < nrClients; i++)
    {
        Client client;
        int x;
        cin >> x;
        while (x--)
        {
            string ingredient;
            cin >> ingredient;
            client.likes[ingredient] = 1;
            ingredients.insert(ingredient);
        }
        cin >> x;
        while (x--)
        {
            string ingredient;
            cin >> ingredient;
            client.dislikes[ingredient] = 1;
            ingredients.insert(ingredient);
        }
    }

}