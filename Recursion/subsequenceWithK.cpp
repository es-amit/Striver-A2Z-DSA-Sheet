#include<bits/stdc++.h>
using namespace std;


void solve(const vector<int>& ip, vector<int>& op, int sum, int k, int index) {
    if (index == ip.size()) {
        if (k == sum) {
            for (auto it : op) {
                cout << it << ' ';
            }
            cout << endl;
        }
        return;
    }
    // take
    op.push_back(ip[index]);
    sum += ip[index];
    solve(ip, op, sum, k, index + 1);

    sum -= ip[index];
    op.pop_back();

    // not take
    solve(ip, op, sum, k, index + 1);
}


int main()
{
    int n,k;
    cin >> n >> k;
    vector<int> ip(n);
    
    for(int i=0;i<n;i++){
        cin >> ip[i];
    }
    vector<int> op;
    solve(ip,op,0,k,0);

    return 0;
}
