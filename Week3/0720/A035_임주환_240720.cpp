#include <iostream>
#include <vector>

using namespace std;

vector<string> split(string s, char c);

int main()
{
    int n;
    cin >> n;

    for(int i = 0 ; i < n ; i++)
    {
        float nums;
        cin >> nums;

        string s;
        getline(cin, s);

        vector<string> operations = split(s, ' ');

        for(int i = 0 ; i < operations.size() ; i++)
        {
            if(operations[i] == "@")
                nums *= 3;
            else if(operations[i] == "%")
                nums += 5;
            else if(operations[i] == "#")
                nums -= 7;
        }

        printf("%.2f\n", nums);
    }
    return 0;
}

vector<string> split(string s, char c)
{
    vector<string> answer;

    string substring;
    for(int i = 0 ; i < s.size() ; i++)
    {
        if(s[i] == c)
        {
            if(substring != "")
            {
                answer.push_back(substring);
                substring = "";
            }
            continue;
        }

        substring += s[i];
    }

    if(substring != "")
        answer.push_back(substring);

    return answer;
}