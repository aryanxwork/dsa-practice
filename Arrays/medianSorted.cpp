#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1); // ensure nums1 is smaller

        int m = nums1.size(), n = nums2.size();
        int low = 0, high = m;

        while (low <= high)
        {
            int partitionX = (low + high) / 2;
            int partitionY = (m + n + 1) / 2 - partitionX;

            int L1 = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int R1 = (partitionX == m) ? INT_MAX : nums1[partitionX];
            int L2 = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            int R2 = (partitionY == n) ? INT_MAX : nums2[partitionY];

            if (L1 <= R2 && L2 <= R1)
            {
                if ((m + n) % 2 == 0)
                    return (max(L1, L2) + min(R1, R2)) / 2.0;
                else
                    return max(L1, L2);
            }
            else if (L1 > R2)
            {
                high = partitionX - 1;
            }
            else
            {
                low = partitionX + 1;
            }
        }

        throw invalid_argument("Input arrays are not sorted.");
    }
};