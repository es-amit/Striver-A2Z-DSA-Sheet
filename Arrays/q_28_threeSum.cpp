#include <bits/stdc++.h>
using namespace std;

bool find3Numbers(int A[], int n, int x)
{
    sort(A, A + n);
    for (int i = 0; i < n; i++)
    {
        int j = i + 1;
        int k = n - 1;
        int elem1 = A[i];
        while (j < k)
        {
            int elem2 = A[j];
            int elem3 = A[k];
            if (elem1 + elem2 + elem3 == x)
            {
                return true;
            }
            else if (elem1 + elem2 + elem3 > x)
            {
                k--;
            }
            else
            {
                j++;
            }
        }
    }
    return false;
}
int main()
{
    int n, x;
    cin >> n >> x;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << find3Numbers(arr, n, x);

    return 0;
}