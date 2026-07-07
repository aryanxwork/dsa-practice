#include <iostream>
#include <vector>
using namespace std;

bool canPlaceFlowers(vector<int> &flowerbed, int n)
{
    int maxFlowers = 0;
    int size = flowerbed.size();

    for (int i = 0; i < size; i++)
    {
        if (0 == flowerbed[i])
        {
            int left = (0 == i) ? 0 : flowerbed[i - 1];
            int right = (size - 1 == i) ? 0 : flowerbed[i + 1];

            if (right == 0 && left == 0)
            {
                flowerbed[i] = 1;
                maxFlowers++;
            }
        }
    }
    if (maxFlowers >= n)
    {
        return true;
    }
    else
        return false;
}