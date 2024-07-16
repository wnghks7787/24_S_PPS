#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n, cur_feels;
    float feel_good;
    float feel_bad;

    float prev_good;
    float prev_bad;

    cin >> n >> cur_feels;

    float GG;
    float GB;
    float BG;
    float BB;

    cin >> GG >> GB >> BG >> BB;

    if(cur_feels == 0)
    {
        feel_good = GG;
        feel_bad = GB;

        prev_good = GG;
        prev_bad = GB;
    }
    else
    {
        feel_good = BG;
        feel_bad = BB;

        prev_good = BG;
        prev_bad = BB;
    }

    for(int i = 1 ; i < n ; i++)
    {
        feel_good = prev_good * GG + prev_bad * BG;
        feel_bad = prev_good * GB + prev_bad * BB;

        prev_good = feel_good;
        prev_bad = feel_bad;
    }

    cout << round(feel_good * 1000) << endl;
    cout << round(feel_bad * 1000) << endl;

    return 0;
}