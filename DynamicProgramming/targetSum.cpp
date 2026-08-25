#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int s = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            s += nums[i];
        }
        if (s % 2 != 0)
        {
            return false;
        }
        int target = s / 2;

        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
        // base cases
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = true;
        }
        if (nums[0] <= target)
            dp[0][nums[0]] = true;

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j <= target; j++)
            {
                bool noTake = dp[i - 1][j];
                bool take = false;
                if (nums[i] <= j)
                {
                    take = dp[i - 1][j - nums[i]];
                }
                dp[i][j] = take || noTake;
            }
        }
        return dp[n - 1][target];
    }
};

bool targetSumSubset(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

    // dp[i][j] represents whether by taking first i items a target of j can be achieved

    // base cases
    //  if amount = 0 -> mark as true (first column)
    //  on first row if nums[0]<=target mark dp[0][nums[0]]=true (means by taking only 1 element this can be achieved)

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    if (nums[0] <= target)
        dp[0][nums[0]] = true;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            bool noTake = dp[i - 1][j]; // not taking -> index changes but target stays same
            bool take = false;          // just an initialization
            if (nums[i] <= j)
            {                                  // to check that we are not going beyond target
                take = dp[i - 1][j - nums[i]]; // taking ->index changes and target also reduces
            }
            dp[i][j] = noTake || take; // any choice can return true and we'll take it
        }
    }
    return dp[n - 1][target];
}