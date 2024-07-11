#include <iostream>
#include <vector>

using namespace std;

float average(vector<int> v);

int main()
{
    int test_case;

    cin >> test_case;

    for(int i = 0 ; i < test_case ; i++)
    {
        int num;
        cin >> num;

        vector<int> scores(num);

        for(int j = 0 ; j < num ; j++)
            cin >> scores[j];

        float avg;
        avg = average(scores);

        int up = 0;
        for(int j = 0 ; j < num ; j++)
        {
            if(scores[j] > avg)
                up++;
        }

        printf("%.3f%%\n", ((float)up/num) * 100);
    }
    return 0;
}

float average(vector<int> v)
{
    int sum = 0;

    for(int i = 0 ; i < v.size() ; i++)
        sum += v[i];

    float answer = (float)sum / v.size();

    return answer;
}