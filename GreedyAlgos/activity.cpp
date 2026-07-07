#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b)
{ // sort by second element ascending
    return a.second < b.second;
}
int activity(vector<int> start, vector<int> end)
{
    vector<pair<int, int>> activities; // vector of pairs that holds  (start,end)
    int n = start.size();
    for (int i = 0; i < n; i++)
    {
        auto p = make_pair(start[i], end[i]); // making pairs
        activities.push_back(p);              // pushing to vector
    }
    sort(activities.begin(), activities.end(), cmp); // sorting on basis of our function
    int count = 1;
    int currEnd = activities[0].second;
    for (int i = 1; i < n; i++)
    {
        if (activities[i].first >= currEnd)
        {
            count++;
            currEnd = activities[i].second;
        }
    }
    return count;
}
int main()
{
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};
    int ans = activity(start, end);
    cout << ans << endl;
}