class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> answer;

        for(int i = 0 ; i < numRows ; i++)
        {
            vector<int> tmp;
            if(i == 0)
            {
                tmp.push_back(1);
            }
            else
            {
                for(int j = 0 ; j <= i ; j++)
                {
                    if(j == 0 || j == i)
                        tmp.push_back(1);
                    else
                        tmp.push_back(answer[i - 1][j] + answer[i - 1][j - 1]);
                }
            }

            answer.push_back(tmp);
        }

        return answer;
    }
};