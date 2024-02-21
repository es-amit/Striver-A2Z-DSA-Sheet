#include <bits/stdc++.h>
using namespace std;

bool isMaxHeap(int arr[], int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && arr[left] > arr[i])
        {
            return false;
        }
        if (right < n && arr[right] > arr[i])
        {
            return false;
        }
    }
    return true;
}