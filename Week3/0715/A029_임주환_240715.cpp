#include <iostream>

using namespace std;

int main()
{
    long int door;
    cin >> door;

    int open;
    cin >> open;

    if(door >= 6)
        cout << "Love is open door" << endl;
    else
    {
        for(int i = 0 ; i < door - 1 ; i++)
        {
            if(open == 0)
                open++;
            else
                open--;

            cout << open << endl;
        }
    }
    return 0;
}