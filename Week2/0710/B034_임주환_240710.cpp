#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> lists(n, 1);
    
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    int j = 0;
    int k = 0;
    for(int i = 0 ; i < n ; i++)
    {
        if(i == lost[j] - 1)
        {
            lists[i]--;
            j++;
        }
        if(i == reserve[k] - 1)
        {
            lists[i]++;
            k++;
        }
    }
    
    for(int i = 0 ; i < n ; i++)
    {
        if(lists[i] == 2)
        {
            if(i == 0)
            {
                if(lists[1] == 0)
                {
                    lists[0] = 1;
                    lists[1] = 1;
                }
            }
            else if(i == n - 1)
            {
                if(lists[n - 2] == 0)
                {
                    lists[n - 1] = 1;
                    lists[n - 2] = 1;
                }
            }
            else if(lists[i - 1] == 0 && lists[i + 1] != 0)
            {
                lists[i] = 1;
                lists[i - 1] = 1;
            }
            else if(lists[i + 1] == 0 && lists[i - 1] != 0)
            {
                lists[i] = 1;
                lists[i + 1] = 1;
            }
        }
    }
    
    for(int i = 1 ; i < n - 1 ; i++)
    {
        if(lists[i] == 2 && lists[i - 1] == 0)
        {
            lists[i] = 1;
            lists[i - 1] = 1;
        }
        else if(lists[i] == 2 && lists[i + 1] == 0)
        {
            lists[i] = 1;
            lists[i + 1] = 1;
        }
    }
    
    
    
    for(int i = 0 ; i < n ; i++)
    {
        if(lists[i] != 0)
            answer++;
    }
    
    return answer;
}