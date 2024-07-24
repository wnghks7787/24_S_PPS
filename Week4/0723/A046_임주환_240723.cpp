#include <iostream>
#include <vector>
#include <algorithm>

#define ENGLISH 26

using namespace std;

int main()
{
    vector<int> first_alpha(ENGLISH, 0);
    int num;
    cin >> num;

    vector<char> represent;

    for(int i = 0 ; i < num ; i++)
    {
        string players;
        cin >> players;

        first_alpha[players[0] - 'a']++;
    }

    for(int i = 0 ; i < ENGLISH ; i++)
    {
        if(first_alpha[i] >= 5)
            represent.push_back(i+'a');
    }

    if(represent.empty())
    {
        cout << "PREDAJA" << endl;
        return 0;
    }

    sort(represent.begin(), represent.end());

    for(int i = 0 ; i < represent.size() ; i++)
        cout << represent[i];
    cout << endl;

    return 0;
}