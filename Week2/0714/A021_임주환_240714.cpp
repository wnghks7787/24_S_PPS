#include <iostream>

using namespace std;

int main()
{
    int n;

    cin >> n;

    int answer = 1;
    for(int i = 0 ; i < n ; i++)
    {
        int tmp;
        cin >> tmp;
        answer += tmp - 1;
    }
    
    cout << answer << endl;
    return 0;
}