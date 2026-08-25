#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int totalCombinations(vector<int> &coins, int target)
    {
        int n = coins.size();
        vector<vector<long long>> dp(n, vector<long long>(target + 1, 0));

        // bases cases
        // if amount = 0 (column 1) we always have one combination by not taking any
        // for first row (only choosing index=0) we can have a combination for multiples of nums[0] otherwise 0

        for (int i = 0; i < n; i++)
        {
            dp[i][0] = 1;
        }
        for (int i = 0; i <= target; i++)
        {
            if (coins[0] <= i && i % coins[0] == 0)
            {
                dp[0][i] = 1;
            }
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j <= target; j++)
            {
                long long noTake = dp[i - 1][j];
                long long take = 0;
                if (coins[i] <= j)
                    take = dp[i][j - coins[i]];
                dp[i][j] = take + noTake;
            }
        }
        return dp[n - 1][target];
    }
    int change(int amount, vector<int> &coins)
    {
        return totalCombinations(coins, amount);
    }
};