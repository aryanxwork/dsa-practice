#include <iostream>
using namespace std;
void findmax(int arr[], int n)
{
    int maxelement = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maxelement)
        {
            maxelement = arr[i];
        }
    }
    cout << "Maximum Element = " << maxelement << endl;
}
int main()
{
    int arr[6] = {13, 46, 24, 52, 20, 9};
    findmax(arr, 6);
}