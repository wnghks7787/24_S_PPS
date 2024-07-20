class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> answer;
        for(int i = left ; i < right+1 ; i++)
        {
            if(is_SDN(i))
                answer.push_back(i);
        }

        return answer;
    }
    
    bool is_SDN(int n) {
        bool SDN = true;
        int divider  = n % 10;
        int dividee = n;
        while(dividee > 0)
        {
            if(divider == 0)
            {
                SDN = false;
                break;
            }
            if(n % divider != 0)
            {
                SDN = false;
                break;
            }

            dividee /= 10;
            divider = dividee % 10;
        }

        return SDN;
    }
};