#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> A(n);
    vector<int> B(n);

    for(int i = 0 ; i < n ; i++)
        cin >> A[i];
    for(int i = 0 ; i < n ; i++)
        cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.rbegin(), B.rend());

    int answer = 0;

    for(int i = 0 ; i < n ; i++)
        answer += (A[i] * B[i]);

    cout << answer << endl;
    
    return 0;
}