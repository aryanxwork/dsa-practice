#include <iostream>
#include <vector>
using namespace std;
int solver(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
{
    if (i == j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int mini = INT32_MAX;
    for (int k = i; k < j; k++)
    {
        int cost = solver(i, k, arr, dp) + solver(k + 1, j, arr, dp) + arr[i - 1] * arr[k] * arr[j];
        mini = min(mini, cost);
    }
    return dp[i][j] = mini;
}
int mcm(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return solver(1, n - 1, arr, dp);
}
int main()
{
    vector<int> arr = {10, 15, 20, 25};
    cout << mcm(arr);
}