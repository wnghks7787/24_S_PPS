#include <iostream>
#include <vector>

using namespace std;

int abs(int a, int b);

int main()
{
    int a, b;
    int n;
    vector<int> preDefined;

    cin >> a >> b;
    cin >> n;
    int answer = 0;

    int start_num = a;

    for(int i = 0 ; i < n ; i++)
    {
        int tmp;
        cin >> tmp;

        preDefined.push_back(tmp);
    }

    for(int i = 0 ; i < n ; i++)
    {
        if(abs(start_num, b) > abs(preDefined[i], b))
            start_num = preDefined[i];
    }

    if(start_num != a)
        answer++;

    answer += abs(start_num, b);
    cout << answer << endl;


    return 0;
}

int abs(int a, int b)
{
    if(a > b)
        return a - b;
    else
        return b - a;
}