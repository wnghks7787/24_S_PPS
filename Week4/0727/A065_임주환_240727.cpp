#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int> > points;

    for(int i = 0 ; i < n ; i++)
    {
        pair<int, int> point;

        cin >> point.first >> point.second;

        points.push_back(point);
    }
    
    sort(points.begin(), points.end());

    for(int i = 0 ; i < n ; i++)
        cout << points[i].first << " " << points[i].second << "\n";

    return 0;
}