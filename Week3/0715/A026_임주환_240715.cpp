#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int check = x;
    int harshad = 0;
    
    while(x > 0)
    {
        harshad += x % 10;
        x /= 10;
    }
    
    if(check % harshad == 0)
        answer = true;
    else
        answer = false;
    return answer;
}