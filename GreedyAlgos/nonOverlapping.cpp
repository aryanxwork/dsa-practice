#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end(), [](auto &a, auto &b)
         {
             return a[1] < b[1]; // sort by end time
         });

    int n = intervals.size();
    int count = 1;

    int prevEnd = intervals[0][1];

    for (int i = 1; i < n; i++)
    {
        int start = intervals[i][0];
        int end = intervals[i][1];

        if (start >= prevEnd)
        {
            count++;
            prevEnd = end;
        }
    }

    return n - count;
}