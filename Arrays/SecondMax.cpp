#include <iostream>
using namespace std;
void findmax(int arr[], int n)
{
    int maxelement = arr[0];
    int secondmax = maxelement;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maxelement)
        {
            secondmax = maxelement;
            maxelement = arr[i];
        }
        else if (arr[i] < maxelement && arr[i] > secondmax)
        {
            secondmax = arr[i];
        }
    }
    cout << "Maximum Element = " << maxelement << endl;
    cout << "Second Maximum Element = " << secondmax << endl;
}
int main()
{
    int arr[6] = {13, 20, 24, 52, 46, 51};
    findmax(arr, 6);
}