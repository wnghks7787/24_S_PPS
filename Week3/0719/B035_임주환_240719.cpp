#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    
    cin >> n >> k;

    vector<int> coins(n);

    for(int i = 0 ; i < n ; i++)
        cin >> coins[i];

    int index = n - 1;
    int count = 0;
    while(index >= 0)
    {
        if(coins[index] <= k)
        {
            k -= coins[index];
            count++;
            continue;
        }

        index--;
    }

    cout << count << endl;

    return 0;
}