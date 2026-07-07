#include <iostream>
#include <vector>
using namespace std;
int returnFrequency(int n, int hash[])
{
    return hash[n];
}
int main()
{
    vector<int> nums = {1, 2, 3, 4, 3, 4, 5, 2, 1, 6, 3, 2, 4, 5, 6, 3, 2, 4, 2, 1, 1, 2, 1, 3, 4, 1};
    int hash[1000] = {0};
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        hash[nums[i]]++;
    }
    cout << returnFrequency(55, hash) << endl;
}