class Solution {
public:
    int addDigits(int num) {
        int answer = num;
        while(answer >= 10)
        {
            answer = 0;
            while(num > 0)
            {
                answer += (num % 10);
                num /= 10;
            }
            num = answer;
        }

        return answer;
    }
};