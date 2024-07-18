#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    int max = 0;
    cin >> n;

    vector<int> trees(n);

    for(int i = 0 ; i < n ; i++)
        cin >> trees[i];

    sort(trees.begin(), trees.end(), greater<int>());

    for(int i = 0 ; i < n ; i++)
        trees[i] += (i+1);

    for(int i = 0 ; i < n ; i++)
    {
        if(max < trees[i])
            max = trees[i];
    }

    cout << max + 1 << endl;
    
    return 0;
}