#include<bits/stdc++.h>
using namespace std;

void PrintSpiralMatrix(vector<vector<int>> matrix,int n,int m){
    int left = 0, right = m-1;
    int top = 0, bottom = n-1;
    while (left <= right && top <= bottom) 
    {
        for(int j= left;j<= right;j++){
            cout << matrix[top][j] << ' ';
        }
        top++;
        
        for(int i= top;i<= bottom;i++){
            cout << matrix[i][right] << ' ';
        }
        right--;
        
        for(int j= right;j>= left;j--){
            cout << matrix[bottom][j]<< ' ';
        }
        bottom--;
        
        for(int i= bottom;i<= top;i++){
            cout << matrix[i][left]<< ' ';
        }
        left++;
    }
    
}
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> matrix(n,vector<int>(n));

    for(int i=0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> matrix[i][j];
        }
    }

    PrintSpiralMatrix(matrix,n,m);
    return 0;
}