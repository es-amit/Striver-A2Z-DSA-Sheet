#include <bits/stdc++.h>
using namespace std;

bool subArrayExists(int arr[], int n)
{
    int sum = 0;
    unordered_set<int> st;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (st.find(sum) != st.end() || sum == 0)
        {
            return true;
        }
        st.insert(sum);
    }
    return false;
}
int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << subArrayExists(arr, n);
    
    return 0;
}