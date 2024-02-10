#include <bits/stdc++.h>
using namespace std;

double MedianOfArrays(vector<int> &array1, vector<int> &array2)
{
    int m = array1.size();
    int n = array2.size();

    double m1 = -1;
    double m2 = -1;
    int i = 0, j = 0;

    for (int count = 0; count <= (m + n) / 2; count++)
    {
        m2 = m1;
        if (i != m && j != n)
        {
            m1 = (array1[i] < array2[j]) ? array1[i++] : array2[j++];
        }
        else if (i < m)
        {
            m1 = array1[i++];
        }
        else if (j < n)
        {
            m1 = array2[j++];
        }
    }

    if ((m + n) % 2 == 1)
    {
        return m1;
    }
    return (m1 + m2) / 2;
}
int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> arr1(n);
    vector<int> arr2(m);
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }
    cout << MedianOfArrays(arr1, arr2);

    return 0;
}