#include <iostream>

#define FIVE_MINUTE 300
#define ONE_MINUTE 60
#define TEN_SECOND 10

using namespace std;

int main()
{
    int t;
    cin >> t;

    if(t % 10 != 0)
    {
        cout << -1 << endl;
        return 0;
    }

    int five_minute = 0;
    int one_minute = 0;
    int ten_second = 0;

    while(t > 0)
    {
        if(t >= FIVE_MINUTE)
        {
            t -= FIVE_MINUTE;
            five_minute++;
            continue;
        }
        if(t >= ONE_MINUTE)
        {
            t -= ONE_MINUTE;
            one_minute++;
            continue;
        }

        t -= TEN_SECOND;
        ten_second++;
    }

    cout << five_minute << " " << one_minute << " " << ten_second << endl;
    return 0;
}