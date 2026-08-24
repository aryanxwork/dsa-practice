#include <bits/stdc++.h>
using namespace std;

int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    dp[m - 1][n - 1] = 1; // destination to destination = one path
    // dp[i][j] represents number of unique paths from that cell to destination

    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (i == m - 1 && j == n - 1)
                continue;
            dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
        }
    }
    return dp[0][0]; // unique paths from start point to destination
}

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Mark obstacles as -1
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (obstacleGrid[i][j] == 1)
                    dp[i][j] = -1;
            }
        }

        // Destination
        if (dp[m - 1][n - 1] != -1)
            dp[m - 1][n - 1] = 1;

        // dp[i][j] = number of paths from (i, j) to destination

        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                // Current cell is an obstacle
                if (dp[i][j] == -1)
                    continue;

                // Destination already initialized
                if (i == m - 1 && j == n - 1)
                    continue;

                if (dp[i + 1][j] != -1)
                    dp[i][j] += dp[i + 1][j];

                if (dp[i][j + 1] != -1)
                    dp[i][j] += dp[i][j + 1];
            }
        }

        return dp[0][0] == -1 ? 0 : dp[0][0];
    }
};
int main()
{
    cout << uniquePaths(3, 2);
}