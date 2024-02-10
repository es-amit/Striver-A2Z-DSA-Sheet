#include <bits/stdc++.h>
using namespace std;

int middle(int A, int B, int C){
        if(A>B&&A>C) 
            return max(B,C);
        else if(C>B)
            return max(A,B);
        else
            return max(C,A);
        
    }
int main()
{
    int a,b,c;
    cin >> a >> b >> c;

    cout << middle(a,b,c);
    return 0;
}
