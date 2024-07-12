class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> answer;

        if(nums.size() == 0)
            return answer;
        if(nums.size() == 1)
        {
            answer.push_back(to_string(nums[0]));
            return answer;
        }

        int start = nums[0];
        int end = nums[0];

        string tmp;

        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(i >= nums.size() - 1)
            {
                tmp = to_string(start);
                answer.push_back(tmp);
                break;
            }

            if(nums[i] + 1 == nums[i+1])
            {
                end = nums[i+1];

                if(i+1 >= nums.size() - 1)
                {
                    tmp = to_string(start) + "->" + to_string(end);
                    answer.push_back(tmp);
                    break;
                }
            }
            else if(i < nums.size() - 1)
            {
                if(start != end)
                {
                    tmp = to_string(start) + "->" + to_string(end);
                    answer.push_back(tmp);
                    start = nums[i+1];
                    end = nums[i+1];
                }
                else
                {
                    tmp = to_string(start);
                    answer.push_back(tmp);
                    start = nums[i+1];
                    end = nums[i+1];
                }
            }
        }

        return answer;
    }
};