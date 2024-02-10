#include<bits/stdc++.h>
using namespace std;

void sortedMatrix(vector<vector<int>>& matrix, int n) {
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans.push_back(matrix[i][j]);
        }
    }
    sort(ans.begin(), ans.end());
    int i = 0;
    for (int j = 0; j < n * n; j++) {
        if (j % n == 0 && j != 0) {
            i++;
        }
        matrix[i][j % n] = ans[j];
    }
}
int main(){
    int n;
    cin >> n;
    vector<vector<int>> matrix(n,vector<int>(n));

    for(int i=0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin >> matrix[i][j];
        }
    }

    sortedMatrix(matrix,n);
    for(int i=0;i<n;i++){
        for(int j = 0;j<n;j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}