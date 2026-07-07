#include <iostream>
#include <vector>
using namespace std;
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int smaller = nums1.size() < nums2.size() ? nums1.size() : nums2.size();
    int larger = nums1.size() < nums2.size() ? nums2.size() : nums1.size();
    int low = 0;
    int high = smaller;
    int totalLength = smaller + larger;
    while (1)
    {
        int partitionX = (low + high) / 2;
        int partitionY = totalLength - partitionX;
    }
}