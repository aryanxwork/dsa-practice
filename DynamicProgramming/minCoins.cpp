#include <bits/stdc++.h>
using namespace std;

int minCoins(vector<int> &denominations, int amount)
{
    int n = denominations.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, INT_MAX));

    // dp[i][j] represents the min coins required till index i to reach an amount j

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 0; // first column (amount =0) can be formed by using 0 coins minimum
    }

    // first row base case
    for (int i = 0; i <= amount; i++)
    {
        if (i >= denominations[0] && i % denominations[0] == 0)
        {
            dp[0][i] = i / denominations[0];
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= amount; j++)
        {
            int noTake = 0 + dp[i - 1][j];
            int take = INT_MAX;
            if (denominations[i] <= j && dp[i][j - denominations[i]] != INT_MAX)
                take = dp[i][j - denominations[i]] + 1; // i only due to unlimited coins
            dp[i][j] = min(take, noTake);
        }
    }
    return dp[n - 1][amount] == INT_MAX ? -1 : dp[n - 1][amount];
}