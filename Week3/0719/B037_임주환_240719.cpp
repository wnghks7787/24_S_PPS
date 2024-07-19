#include <iostream>
#include <vector>

using namespace std;

int abs(int a, int b);

int main()
{
    int n;
    cin >> n;

    vector<int> lightbulbs(n);
    vector<int> answer(n, 0);

    for(int i = 0 ; i < n ; i++)
        cin >> lightbulbs[i];

    int check = 0;

    for(int i = 0 ; i < n ; i++)
    {
        if(lightbulbs[i] == answer[i])
            continue;

        answer[i] = abs(answer[i], 1);

        if(i + 1 < n)
            answer[i+1] = abs(answer[i+1], 1);

        if(i + 2 < n)
            answer[i+2] = abs(answer[i+2], 1);

        check++;
    }

    cout << check << endl;

    return 0;
}

int abs(int a, int b)
{
    return (a - b) >= 0 ? a - b : b - a;
}