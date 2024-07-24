class NumArray {
public:
    vector<int>* numArray;
    NumArray(vector<int>& nums) {
        numArray = &nums;
    }
    
    int sumRange(int left, int right) {
        int answer = 0;

        for(int i = left ; i < right + 1 ; i++)
            answer += (*numArray)[i];

        return answer;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */