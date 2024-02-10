#include <bits/stdc++.h>
using namespace std;

int PalinArray(int a[], int n)
    {
    	for(int i=0;i<n;i++){
    	    int x = a[i];
    	    int rev=0;
    	    while(x>0){
    	        int digit = x%10;
    	        rev = rev*10+digit;
    	        x/=10;
    	    }
    	    if(a[i] != rev) return 0;
    	}
    	return 1;
    }
int main()
{
    int n;
    cin >> n;

    int arr1[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    cout << PalinArray(arr1,n);

    return 0;
}