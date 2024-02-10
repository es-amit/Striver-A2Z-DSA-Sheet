#include<bits/stdc++.h>
using namespace std;

void transposeMatrix(vector<vector<int>>& matrix,int n,int m){

    for(int i=0;i<n;i++){
        for(int j = 1;j<m;j++){
            if(j>i){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
}
void reverseRow(vector<vector<int>>& matrix,int n){
    for(int i=0;i<n;i++){
        reverse(matrix[i].begin(),matrix[i].end());
    }
}

void rotateclockwise(vector<vector<int>>& matrix,int n,int m){
    transposeMatrix(matrix,n,m);
    reverseRow(matrix,n);

}
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> matrix(n,vector<int>(m));

    for(int i=0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> matrix[i][j];
        }
    }

    rotateclockwise(matrix,n,m);
    for(int i=0;i<n;i++){
        for(int j = 0;j<m;j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}