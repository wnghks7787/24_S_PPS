class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int shortest_length = strs[0].size();
        string prefix = "";

        for(int i = 0 ; i < strs.size() ; i++)
        {
            if(strs[i].size() < shortest_length)
                shortest_length = strs[i].size();
        }

        for(int i = 0 ; i < shortest_length ; i++)
        {
            char current_prefix_char = strs[0][i];
            bool prefix_ok = true;
            for(int j = 0 ; j < strs.size() ; j++)
            {
                if(strs[j][i] != current_prefix_char)
                {
                    prefix_ok = false;
                    break;
                }
            }

            if(prefix_ok)
                prefix += current_prefix_char;
            else
                break;
        }

        return prefix;
    }
};