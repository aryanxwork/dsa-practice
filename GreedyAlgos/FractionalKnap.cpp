#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
double fknap(double W, vector<double> weight, vector<double> values)
{
    int n = weight.size();
    vector<pair<double, pair<double, double>>> nums;
    int maxprofit = 0;
    for (int i = 0; i < n; i++)
    {
        double r = values[i] / weight[i];
        nums.push_back({r, make_pair(values[i], weight[i])});
    }
    sort(nums.begin(), nums.end(), [](const auto &a, const auto &b)
         { return a.first > b.first; });
    for (int i = 0; i < n; i++)
    {
        double itemwt = nums[i].second.second;
        double itemval = nums[i].second.first;
        if (itemwt < W)
        {
            W -= itemwt;
            maxprofit += itemval;
        }
        else
        {
            double fraction = W / itemwt;
            maxprofit += (fraction * itemval);
            break;
        }
    }
    return maxprofit;
}
int main()
{
    vector<double> values = {2, 3, 1, 5, 1};
    vector<double> weight = {3, 5, 2, 6, 1};
    double W = 10;
    cout << fknap(W, weight, values);
}
