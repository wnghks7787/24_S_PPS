#include <iostream>
#include <vector>
#include <cctype>

#define ENGLISH 26

using namespace std;

int main()
{
    vector<int> alpha(ENGLISH, 0);

    string input;
    cin >> input;

    for(int i = 0 ; i < input.size() ; i++)
        alpha[toupper(input[i]) - 'A']++;

    int max = 0;
    char max_alpha = '?';

    for(int i = 0 ; i < ENGLISH ; i++)
    {
        if(alpha[i] == 0)
            continue;

        if(max < alpha[i])
        {
            max = alpha[i];
            max_alpha = i + 'A';
            continue;
        }

        if(max == alpha[i])
        {
            max_alpha = '?';
        }
    }
    
    cout << max_alpha << endl;

    return 0;
}