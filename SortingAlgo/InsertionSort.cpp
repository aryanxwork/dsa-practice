#include <iostream>
using namespace std;
void insertionsort(int arr[], int n)
{
    for (int i = 0; i <= n - 1; i++)
    {
        int j = i;
        while (j > 0 && arr[j] < arr[j - 1])
        {
            swap(arr[j], arr[j - 1]);
            j--;
        }
    }
}
void printarr(int arr[], int n)
{
    cout << "Array = ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int arr[6] = {13, 46, 24, 52, 20, 9};
    insertionsort(arr, 6);
    printarr(arr, 6);
}