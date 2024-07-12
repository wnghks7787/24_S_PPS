/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int answer = 0;

        for(int i = 0 ; i < employees.size() ; i++)
        {
            if(employees[i]->id != id)
                continue;

            answer += employees[i]->importance;

            for(int j = 0 ; j < employees[i]->subordinates.size() ; j++)
            {
                answer += getImportance(employees, employees[i]->subordinates[j]);
            }

            break;
        }

        return answer;
    }
};