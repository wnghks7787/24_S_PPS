#include <iostream>

#define NUM 5

using namespace std;

int main()
{
    int answer = 0;

    for(int i = 0 ; i < NUM ; i++)
    {
        int nums;

        cin >> nums;
        answer += (nums * nums);
    }

    cout << answer % 10 << endl;
    
    return 0;
}