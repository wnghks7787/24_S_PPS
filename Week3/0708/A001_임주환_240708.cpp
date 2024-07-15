class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        
        int answer = 0;
        int current = 0;
        for(int i = 0 ; i < s.size() ; i++)
        {
            if(current >= g.size())
                break;
            
            if(g[current] <= s[i])
            {
                answer++;
                current++;
            }
            else
            {
                continue;
            }
        }

        return answer;
    }
};