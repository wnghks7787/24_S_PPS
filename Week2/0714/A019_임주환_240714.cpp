#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int A, B, C;
    int mul;

    vector<int> nums(10, 0);

    cin >> A;
    cin >> B;
    cin >> C;

    mul = A * B * C;

    while(mul > 0)
    {
        nums[mul%10]++;
        mul /= 10;
    }
    
    for(int i = 0 ; i < nums.size() ; i++)
        cout << nums[i] << endl;
    return 0;
}