class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> answer1;
        stack<char> answer2;

        for(int i = 0 ; i < s.size() ; i++)
        {
            if(s[i] == '#')
            {
                if(!answer1.empty())
                    answer1.pop();
                
                continue;
            }

            answer1.push(s[i]);
        }

        for(int i = 0 ; i < t.size() ; i++)
        {
            if(t[i] == '#')
            {
                if(!answer2.empty())
                    answer2.pop();

                continue;
            }

            answer2.push(t[i]);
        }

        return answer1 == answer2 ? true : false;
    }
};