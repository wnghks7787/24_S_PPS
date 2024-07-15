class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        int twenty = 0;

        for(int i = 0 ; i < bills.size() ; i++)
        {
            if(bills[i] == 5)
            {
                five++;
                continue;
            }

            if(bills[i] == 10)
            {
                if(five > 0)
                {
                    five--;
                    ten++;
                    continue;
                }
                return false;
            }

            if(bills[i] == 20)
            {
                if(ten > 0 && five > 0)
                {
                    five--;
                    ten--;
                    twenty++;
                    continue;
                }
                else if(five > 2)
                {
                    five -= 3;
                    twenty++;
                    continue;
                }
            }

            return false;
        }

        return true;
    }
};