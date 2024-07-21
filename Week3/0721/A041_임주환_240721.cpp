#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s) {
    string answer = "";
    
    for(int i = 0 ; i < s.size() ; i++)
    {
        if(i == 0)
        {
            answer += toupper(s[i]);
            continue;
        }
        
        if(s[i-1] == ' ')
        {
            answer += toupper(s[i]);
            continue;
        }
        
        answer += tolower(s[i]);
    }
    
    return answer;
}