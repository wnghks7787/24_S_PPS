#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string str;

    cin >> str;

    vector<int> to_sort(str.size());

    for(int i = 0 ; i < str.size() ; i++)
        to_sort[i] = (str[i] - '0');
    
    sort(to_sort.begin(), to_sort.end(), greater<int>());

    for(int i = 0 ; i < str.size() ; i++)
        cout << to_sort[i];
    cout << endl;

    return 0;
}