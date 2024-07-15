#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int  n;
    int Y = 0, M = 0;

    cin >> n;

    vector<int> call(n);

    for(int i = 0 ; i < n ; i++)
        cin >> call[i];
    
    for(int i = 0 ; i < n ; i++)
    {
        Y += (call[i] / 30 + 1) * 10;
        M += (call[i] / 60 + 1) * 15;
    }

    if(Y == M)
        cout << "Y M " << Y << endl;
    else if(Y < M)
        cout << "Y " << Y << endl;
    else
        cout << "M " << M << endl;

    return 0;
}