#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<float, int> a, pair<float, int> b)
{
    if(a.first != b.first)
        return a.first > b.first;
    
    return a.second < b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    vector<int> stage_people(N+1, 0);
    
    for(int i = 0 ; i < stages.size() ; i++)
    {
        for(int j = 0 ; j < stages[i] ; j++)
        {
            stage_people[j]++;
        }
    }
    
    vector<pair<float, int>> fail(N);
    for(int i = 0 ; i < N ; i++)
    {
        pair<float, int> tmp;
        if(stage_people[i] == 0)
            tmp.first = 0;
        else
            tmp.first = (float)(stage_people[i]-stage_people[i+1]) / stage_people[i];
        tmp.second = i+1;
        
        fail[i] = tmp;
    }
    
    sort(fail.begin(), fail.end(), compare);
    
    for(int i = 0 ; i < fail.size() ; i++)
        answer.push_back(fail[i].second);
    
    return answer;
}