class Solution {
public:
    int balancedStringSplit(string s) {
        stack<char> LR;

        int answer = 0;
        for(int i = 0 ; i < s.size() ; i++)
        {
            if(LR.empty())
            {
                LR.push(s[i]);
                continue;
            }
            
            if(LR.top() != s[i])
                LR.pop();
            else
                LR.push(s[i]);

            if(LR.empty())
                answer++;
        }

        return answer;
    }
};