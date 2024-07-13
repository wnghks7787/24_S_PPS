class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int pivot = nums.size() / 2;

        int start = 0;
        int end = nums.size();

        for(;;)
        {
            if(start+1 == end)
            {
                if(nums[start] == target)
                    return start;
                if(nums[start] > target)
                    return start;
                if(nums[start] < target)
                    return start+1;
            }

            if(nums[pivot] == target)
                return pivot;

            if(nums[pivot] < target)
            {
                start = pivot;

                pivot = (start + end) / 2;
            }
            else if(nums[pivot] > target)
            {
                end = pivot;

                pivot = (start + end) / 2;
            }
        }
    }
};