#include <iostream>
#include <vector>

#define COUNT 10
#define NUM 42

using namespace std;

int main()
{
    vector<int> answer(NUM, 0);

    for(int i = 0 ; i < COUNT ; i++)
    {
        int tmp;
        cin >> tmp;

        answer[tmp % NUM]++;
    }

    int count = 0;
    for(int i = 0 ; i < NUM ; i++)
    {
        if(answer[i] != 0)
            count++;
    }

    cout << count << endl;

    return 0;
}