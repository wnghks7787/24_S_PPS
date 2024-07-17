#include <iostream>
#include <stack>
#include <algorithm>
#include <string>

using namespace std;

string decode(string key);
string stackToString(stack<char> v);

int main()
{
    int n;

    cin >> n;

    for(int i = 0 ; i < n ; i++)
    {
        string keylogger;
        cin >> keylogger;

        cout << decode(keylogger) << endl;
    }

    return 0;
}

string decode(string key)
{
    int cursor = 0;

    stack<char> pw;
    stack<char> pw2;
    for(int i = 0 ; i < key.length() ; i++)
    {
        // backspace;
        if(key[i] == '-')
        {
            if(!pw.empty())
                pw.pop();

            continue;
        }

        // backward arrow
        if(key[i] == '<')
        {
            if(!pw.empty())
            {
                pw2.push(pw.top());
                pw.pop();
            }

            continue;
        }

        // foreward arrow
        if(key[i] == '>')
        {
            if(!pw2.empty())
            {
                pw.push(pw2.top());
                pw2.pop();
            }

            continue;
        }

        // general
        pw.push(key[i]);
    }

    while(!pw2.empty())
    {
        pw.push(pw2.top());
        pw2.pop();
    }

    return stackToString(pw);
}

string stackToString(stack<char> v)
{
    string str;

    while(!v.empty())
    {
        str += v.top();
        v.pop();
    }

    reverse(str.begin(), str.end());

    return str;
}