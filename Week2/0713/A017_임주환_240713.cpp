#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> nums(10, 0);

    int n;
    cin >> n;

    while(n > 0)
    {
        nums[n%10]++;
        n /= 10;
    }

    nums[6] += nums[9];
    if(nums[6] % 2 != 0)
    {
        nums[6] /= 2;
        nums[6]++;
    }
    else
        nums[6] /= 2;

    int max = 0;
    for(int i = 0 ; i < 9 ; i++)
    {
        if(max < nums[i])
            max = nums[i];
    }

    cout << max << endl;

    return 0;
}