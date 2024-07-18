#include <iostream>

#define NUMBER 5
#define SCORE_NUM 4

using namespace std;

int main()
{
    int max = 0;
    int max_i = 0;
    for(int i = 0 ; i < NUMBER ; i++)
    {
        int score = 0;
        for(int j = 0 ; j < SCORE_NUM ; j++)
        {
            int tmp;
            cin >> tmp;
            score += tmp;
        }

        if(max < score)
        {
            max_i = i;
            max = score;
        }
    }

    cout << max_i+1 << " " << max << endl;

    return 0;
}