#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int platforms(vector<int> arrivals, vector<int> departues)
{
    int n = arrivals.size();
    int platformreq = 0;
    int maxplatform = 0;
    sort(arrivals.begin(), arrivals.end());
    sort(departues.begin(), departues.end());
    int i = 0;
    int j = 0;
    while (i < n && j < n)
    {
        if (arrivals[i] <= departues[j])
        {
            platformreq++;
            maxplatform = max(platformreq, maxplatform);
            i++;
        }
        else
        {
            platformreq--;
            j++;
        }
    }
    return maxplatform;
}
int main()
{
    vector<int> arrivals = {900, 940, 950, 1100, 1500, 1800};
    vector<int> departues = {910, 1200, 1120, 1130, 1900, 2000};
    cout << platforms(arrivals, departues);
}