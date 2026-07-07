#include <iostream>
#include <vector>
using namespace std;
int knap(vector<int> &wt, vector<int> &val, int W, int n, vector<vector<int>> &dp)
{
    if (n == 0 || W == 0)
    {
        return 0;
    }
    if (dp[n][W] != -1)
    {
        return dp[n][W];
    }

    int itemWt = wt[n - 1];
    int itemVal = val[n - 1];
    if (itemWt <= W)
    {
        // include
        int ans1 = knap(wt, val, W - itemWt, n - 1, dp) + itemVal;

        // exclude
        int ans2 = knap(wt, val, W, n - 1, dp);
        dp[n][W] = max(ans1, ans2);
        return dp[n][W];
    }
    else
    {
        // exclude
        dp[n][W] = knap(wt, val, W, n - 1, dp);
        return dp[n][W];
    }
}
int main()
{
    vector<int> val = {15, 14, 10, 45, 30};
    vector<int> wt = {2, 5, 1, 3, 4};
    int w = 7;
    int n = 5;
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, -1));
    cout << knap(wt, val, w, n, dp) << endl;
    // for (int i = 0; i < n + 1; i++)
    // {
    //     for (int j = 0; j < w + 1; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}