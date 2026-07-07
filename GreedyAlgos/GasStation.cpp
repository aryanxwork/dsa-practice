#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int currentGas = 0;
    int n = gas.size();
    int start = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += (gas[i] - cost[i]);
    }
    if (sum < 0)
    {
        return -1;
    }

    for (int i = 0; i < n; i++)
    {
        currentGas += (gas[i] - cost[i]);

        if (currentGas < 0)
        {
            start = i + 1;
            currentGas = 0;
        }
    }
    return start;
}