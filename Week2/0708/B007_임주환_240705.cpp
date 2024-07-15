class Solution {
public:
    int search(vector<int>& nums, int target) {

        int pivot = nums.size() / 2;

        int start = 0;
        int end = nums.size();

        int iter = 1;

        while(1)
        {
            if(nums[pivot] == target)
                return pivot;
            else if(nums[pivot] > target)
            {
                end = pivot;
            }
            else
            {
                start = pivot + 1;
            }

            if(start >= nums.size() || end < 0)
                return -1;

            pivot = (start + end) / 2;

            if(iter * iter > nums.size())
                return -1;
            iter++;
        }
    }
};