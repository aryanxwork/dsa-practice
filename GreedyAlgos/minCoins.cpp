#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int minimumAddedCoins(vector<int> &coins, int target)
{
    sort(coins.begin(), coins.end());
    int reach = 0;
    int minCoins = 0;
    int n = coins.size();
    int i = 0;
    while (reach < target)
    {
        if (i < n && coins[i] <= reach + 1)
        {
            reach += coins[i];
            i++;
        }
        else
        {
            minCoins++;
            reach += reach + 1;
        }
    }
    return minCoins;
}
int main()
{
    vector<int> nums = {1, 4, 10};
    int target = 19;
    cout << minimumAddedCoins(nums, target);
}