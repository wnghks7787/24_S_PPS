#include <iostream>
#include <vector>

#define STATION 4

using namespace std;

int main()
{
    int people = 0;
    int max = 0;

    for(int i = 0 ; i < STATION ; i++)
    {
        int in, out;
        cin >> out >> in;

        people -= out;
        people += in;

        if(people > max)
            max = people;
    }
    cout << max << endl;
    
    return 0;
}