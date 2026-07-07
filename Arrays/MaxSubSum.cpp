#include <iostream>
#include <vector>
using namespace std;
void maxsubarrsum(vector<int> &arr)
{
    int maxi = arr[0];
    int currsum = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        currsum = max(arr[i], currsum + arr[i]);
        maxi = max(maxi, currsum);
    }
    cout << "Maximum Subarray Sum is: " << maxi << endl;
}
int main()
{
    vector<int> arr  ={-2, -5, 6, -2, -3, 1, 5, -6};
    maxsubarrsum(arr);
    return 0;
}

// curr=arr[i] or curr+arr[i] choose which is larger
// maxi=max(maxi,curr) update maxi if curr is larger
// Dry run example with array {-2, -5, 6, -2, -3, 1, 5, -6} 
// i=0 currsum=-2 maxi=-2
// i=1 currsum=max(-5,-2+-5)=-5 maxi=max(-2,-5)=-2
// i=2 currsum=max(6,-5+6)=6 maxi=max(-2,6)=6
// i=3 currsum=max(-2,6+-2)=4 maxi=max(6,4)=6
// i=4 currsum=max(-3,4+-3)=1 maxi=max(6,1)=6
// i=5 currsum=max(1,1+1)=2 maxi=max(6,2)=6
// i=6 currsum=max(5,2+5)=7 maxi=max(6,7)=7
// i=7 currsum=max(-6,7+-6)=1 maxi=max(7,1)=7
// Final Output: 7
