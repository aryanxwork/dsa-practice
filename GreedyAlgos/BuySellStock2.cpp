#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int buy = 0;
    int sell = 1;
    int maxProfit = 0;
    int n = prices.size();

    while (sell < n)
    {
        if (prices[sell] > prices[sell - 1])
        {
            if (sell == n - 1)
            {
                maxProfit += prices[sell] - prices[buy]; // last day rally
                break;
            }
            else
            {
                sell++;
            }
        }
        else
        {
            maxProfit += prices[sell - 1] - prices[buy];
            buy = sell;
            sell++;
        }
    }
    return maxProfit;
}

// standard solution
//  int maxProfit(vector<int>& prices) {
//      int profit = 0;

//     for (int i = 1; i < prices.size(); i++) {
//         if (prices[i] > prices[i - 1]) {
//             profit += prices[i] - prices[i - 1];
//         }
//     }

//     return profit;
// }