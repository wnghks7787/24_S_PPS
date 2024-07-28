#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for(int i = 0 ; i < n ; i++)
    {
        string OX;
        cin >> OX;

        int score = 0;
        int accumulate = 0;

        for(int j = 0 ; j < OX.size() ; j++)
        {
            if(OX[j] == 'O')
            {
                accumulate++;
                score += accumulate;
            }
            else
                accumulate = 0;
        }

        cout << score << endl;
    }
    return 0;
}