#include <iostream>
using namespace std;
void reverse(int arr[], int si, int ei)
{
    for (int i = si, j = ei; i <= j; i++, j--)
    {
        swap(arr[i], arr[j]);
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4};
    reverse(arr, 0, 3);
    // reverse(arr, 2, 3);
    for (int i = 0; i < 4; i++)
    {
        cout << arr[i] << " ";
    }
}