#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int exchange(vector<int> coins, int amount)
{
    int n = coins.size();
    int count = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (amount - coins[i] >= 0)
        {
            count += amount / coins[i];
            amount = amount % coins[i];
        }
    }
    return count;
}
int main()
{
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500};
    int amt = 408;
    cout << exchange(coins, amt);
}