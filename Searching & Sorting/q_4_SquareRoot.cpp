#include <bits/stdc++.h>
using namespace std;

int countSquares(int N) {
        // code here
        int cnt = 0;
        if(N == 1) return 0;
        for(int i=1;i<sqrt(N);i++){
            if(i*i < N){
                cnt++;
            }
        }
        return cnt;
    }
int main()
{
    int n;
    cin >> n;

    cout << countSquares(n);
    return 0;
}
