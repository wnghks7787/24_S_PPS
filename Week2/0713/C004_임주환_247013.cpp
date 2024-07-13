#include <iostream>

using namespace std;

int divide_sum(int x);

int main()
{
    int n;

    cin >> n;

    int answer = 0;
    for(int i = 1 ; i < n ; i++)
    {
        if(divide_sum(i) == n)
        {
            answer = i;
            break;
        }
    }

    cout << answer << endl;

    return 0;
}

int divide_sum(int x)
{
    int answer = 0;
    answer += x;

    while(x > 0)
    {
        answer += (x % 10);
        x /= 10;
    }

    return answer;
}