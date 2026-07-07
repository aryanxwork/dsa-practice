#include <bits\stdc++.h>
using namespace std;
int singleNonDuplicate(vector<int> &nums)
{
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    while (low < high)
    {
        int mid = (high + low) / 2;
        if (nums[mid] == nums[mid + 1])
        {
            if ((high - mid - 1) % 2 == 0)
            {
                // right side is safe because there are even elements and single element can be one only
            }
            else
            {
                low = mid; // right side left with odd elements so single is here
            }
        }
        else if (nums[mid] == nums[mid - 1])
        {
            if ((mid - low - 1) % 2 == 0)
            {
                // left side safe->even elements
            }
            else
            {
                high = mid;
            }
        }
        else
        {
            return nums[mid]; // mid is not equal to either elements therefore it is the single one
        }
    }
}
int main()
{
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << singleNonDuplicate(nums);
}