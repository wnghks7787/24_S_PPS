#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> bridge(n);

    for(int i = 0 ; i < n ; i++)
        cin >> bridge[i];

    int start;
    cin >> start;
    start--;

    queue<int> check_stones;
    check_stones.push(start);

    while(check_stones.size() > 0)
    {
        start = check_stones.front();
        check_stones.pop();
        int jump = bridge[start];
        bridge[start] = 0;

        if(start >= jump)
            if(bridge[start-jump] != 0)
                check_stones.push(start-jump);

        if(n-start-1 >= jump)
            if(bridge[start+jump] != 0)
                check_stones.push(start+jump);
    }

    int count = 0;
    for(int i = 0 ; i < n ; i++)
    {
        if(bridge[i] == 0)
            count++;
    }

    cout << count << endl;

    return 0;
}