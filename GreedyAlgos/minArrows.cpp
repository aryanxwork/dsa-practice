#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int findMinArrowShots(vector<vector<int>> &points)
{
    sort(points.begin(), points.end(), [](auto &a, auto &b)
         { return a[1] < b[1]; });
    int distinctIntervals = 1;
    int currEnd = points[0][1];
    int n = points.size();
    for (int i = 1; i < n; i++)
    {
        if (points[i][0] > currEnd)
        {
            distinctIntervals++;
            currEnd = points[i][1];
        }
    }
    return distinctIntervals;
}
int main()
{
    vector<vector<int>> points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    cout << findMinArrowShots(points);
}