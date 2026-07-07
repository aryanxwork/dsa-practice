#include <iostream>
using namespace std;
// this does not work for k=1
// void rotatebyk(int arr[], int n, int k)
// {
//     if (k >= n)
//     {
//         k = k % n;
//     }

//     for (int i = 0; i < k; i++)
//     {
//         int swapidx = i + k;
//         if (swapidx >= n)
//         {
//             swapidx = swapidx % n;
//             swap(arr[i], arr[swapidx]);
//         }
//         else
//             swap(arr[i], arr[swapidx]);
//     }
// }
void reverse(int arr[], int si, int ei)
{
    for (int i = si, j = ei; i <= j; i++, j--)
    {
        swap(arr[i], arr[j]);
    }
}
void rotate(int arr[], int n, int k)
{
    if (k >= n)
    {
        k = k % n;
    }
    reverse(arr, 0, n - 1);
    reverse(arr, 0, k - 1);
    reverse(arr, k, n - 1);
}
int main()
{
    int arr[4] = {1, 2, 3, 4};
    rotate(arr, 4, 2);
    for (int i = 0; i < 4; i++)
    {
        cout << arr[i] << " ";
    }
}