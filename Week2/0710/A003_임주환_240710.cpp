class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int v_size = digits.size();

        for(int i = v_size - 1 ; i >= 0 ; i--)
        {
            digits[i]++;

            if(digits[i] < 10)
                break;
            
            if(i == 0)
            {
                digits[i] = 0;
                digits.insert(digits.begin(), 1);
            }
            else
            {
                digits[i] = 0;
            }
        }

        return digits;
    }
};