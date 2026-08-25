#include <bits/stdc++.h>
using namespace std;

int totalSubsets(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));

    // dp[i][j] represents the count of subsets possible to create a sum of j using first i elements in nums

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1; // target = 0 can be formed from every index
    }
    if (nums[0] <= target)
        dp[0][nums[0]] = 1; // if first number can create a subset by itself

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            int noTake = dp[i - 1][j];
            int take = 0;
            if (nums[i] <= j)
                take = dp[i - 1][j - nums[i]];
            dp[i][j] = noTake + take;
        }
    }
    return dp[n - 1][target];
}