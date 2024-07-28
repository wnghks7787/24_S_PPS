#include <iostream>

using namespace std;

int decode(char c);

int main()
{
    string call_str;
    
    cin >> call_str;

    int answer = 0;

    for(int i = 0 ; i < call_str.size() ; i++)
        answer += decode(call_str[i]);

    cout << answer << endl;

    return 0;
}

int decode(char c)
{
    if(c >= 'W')
        return 10;
    if(c >= 'T')
        return 9;
    if(c >= 'P')
        return 8;
    if(c >= 'M')
        return 7;
    if(c >= 'J')
        return 6;
    if(c >= 'G')
        return 5;
    if(c >= 'D')
        return 4;

    return 3;
}