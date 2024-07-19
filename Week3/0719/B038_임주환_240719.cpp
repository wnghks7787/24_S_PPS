#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, snake;

    cin >> n >> snake;
    vector<int> fruits(n);

    for(int i = 0 ; i < n ; i++)
        cin >> fruits[i];

    sort(fruits.begin(), fruits.end());

    for(int i = 0 ; i < n ; i++)
    {
        if(snake >= fruits[i])
            snake++;

        else
            break;
    }
    cout << snake << endl;
    
    return 0;
}