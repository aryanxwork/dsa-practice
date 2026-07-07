#include <iostream>
#include <vector>
using namespace std;
int activitySelection(vector<int> start, vector<int> end)
{
    // endings sorted-first always selected-loop-select non overlapping-sorted end time is answer to all confusions
    int maxActivities = 1;
    int currEnd = end[0];
    for (int i = 1; i < start.size(); i++)
    {
        if (currEnd <= start[i]) // end[i-1] not used because it compares unused activitiy's end time with new
        {
            maxActivities++;
            currEnd = end[i];
        }
    }
    return maxActivities;
}
int main()
{
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};
    int ans = activitySelection(start, end);
    cout << ans << endl;
}