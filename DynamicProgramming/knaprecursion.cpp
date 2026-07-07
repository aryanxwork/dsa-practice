#include <iostream>
#include <vector>
using namespace std;
int knap(vector<int> &wt, vector<int> &val, int W, int n)
{
    if (n == 0 || W == 0)
    {
        return 0;
    }

    int itemWt = wt[n - 1];
    int itemVal = val[n - 1];
    if (itemWt <= W)
    {
        // include
        int ans1 = knap(wt, val, W - itemWt, n - 1) + itemVal;

        // exclude
        int ans2 = knap(wt, val, W, n - 1);
        return max(ans1, ans2);
    }
    else
    {
        // exclude
        return knap(wt, val, W, n - 1);
    }
}
int main()
{
    vector<int> val = {15, 14, 10, 45, 30};
    vector<int> wt = {2, 5, 1, 3, 4};
    int w = 7;
    int n = 5;
    cout << knap(wt, val, w, n);
}