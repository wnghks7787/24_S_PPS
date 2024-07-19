#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> split(string str, char divider);

int main()
{
    string equation;

    cin >> equation;

    vector<string> str_split = split(equation, '-');

    int answer = 0;
    for(int i = 0 ; i < str_split.size() ; i++)
    {
        vector<string> int_sum = split(str_split[i], '+');
        int sum = 0;
        for(int j = 0 ; j < int_sum.size() ; j++)
            sum += stoi(int_sum[j]);

        if(i == 0)
            answer += sum;
        else
            answer -= sum;
    }

    cout << answer << endl;
    
    return 0;
}

vector<string> split(string str, char divider)
{
    int len = str.length();
    vector<string> result;

    string substr;
    for(int i = 0 ; i < len ; i++)
    {
        if(str[i] == divider)
        {
            result.push_back(substr);
            substr = "";
        }
        else
            substr += str[i];
    }
    if(substr != "")
        result.push_back(substr);
    return result;
}