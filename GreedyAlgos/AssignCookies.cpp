#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findContentChildren(vector<int> &g, vector<int> &s)
{
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int maxChild = 0;
    int i = 0;
    int j = 0;

    while (i < g.size() && j < s.size())
    {
        if (s[j] >= g[i])
        {
            // assign cookie
            maxChild++;
            j++;
            i++;
        }
        else
        {
            j++;
        }
    }
    return maxChild;
}