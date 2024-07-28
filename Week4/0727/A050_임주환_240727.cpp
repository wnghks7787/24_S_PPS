#include <iostream>

using namespace std;

char decode(char c);

int main()
{
    string password;

    cin >> password;

    string answer = "";
    for(int i = 0 ; i < password.size() ; i++)
        answer += decode(password[i]);

    cout << answer << endl;
    
    return 0;
}

char decode(char c)
{
    if(c == 'A')
        return 'X';
    if(c == 'B')
        return 'Y';
    if(c == 'C')
        return 'Z';

    return c - 3;
}