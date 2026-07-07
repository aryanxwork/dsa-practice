#include <iostream>
#include <vector>
#include <string>
using namespace std;
int lcs(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                int ans1 = dp[i - 1][j];
                int ans2 = dp[i][j - 1];
                dp[i][j] = max(ans1, ans2);
            }
        }
    }

    return dp[n][m];
}
int main()
{
    string s = "abd";
    string t = "abde";
    cout << lcs(s, t);
}
