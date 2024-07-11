#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for(int i = 0 ; i < skill_trees.size() ; i++)
    {
        int current = 0;
        bool flag = true;
        for(int j = 0 ; j < skill_trees[i].size() ; j++)
        {
            for(int k = 0 ; k < skill.size() ; k++)
            {
                if(k > current && skill_trees[i][j] == skill[k])
                {
                    flag = false;
                    break;
                }
                else if(k == current && skill_trees[i][j] == skill[k])
                {
                    current++;
                    break;
                }
            }
        }
        if(flag)
            answer++;
    }
    
    return answer;
}