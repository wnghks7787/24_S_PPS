#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> music(8);

    for(int i = 0 ; i < 8 ; i++)
    {
        cin >> music[i];
    }

    if(music[0] != 1 && music[0] != 8)
    {
        cout << "mixed" << endl;
        return 0;
    }

    if(music[0] == 1)
    {
        for(int i = 1 ; i < 8 ; i++)
        {
            if(music[i] != i+1)
            {
                cout << "mixed" << endl;
                return 0;
            }
        }
        cout << "ascending" << endl;
        return 0;
    }
    else
    {
        for(int i = 1 ; i < 8 ; i++)
        {
            if(music[i] != 8-i)
            {
                cout << "mixed" << endl;
                return 0;
            }
        }
        cout << "descending" << endl;
    }
    return 0;
}