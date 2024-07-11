class Solution {
public:
    int countPrimes(int n) {
        int prime = 0;

        vector<int> num_table(n+1, 1);

        for(int i = 2 ; i < n ; i++)
        {
            if(num_table[i] == 1)
            {
                int x = 1;
                while(1)
                {
                    if(i * x > n)
                        break;
                    num_table[i * x] = 0;
                    x++;
                }
                prime++;
            }
        }

        return prime;
    }
};