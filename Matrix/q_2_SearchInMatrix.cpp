#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0;
        int high = m*n-1;

        while(low<=high){
            int mid = low+(high - low)/2;
            int elem = matrix[mid/n][mid%n];
            if(elem == target){
                return true;
            }
            else if(elem < target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return false;
    }
int main(){
    int n,m, target;
    cin >> n >> m >> target;
    vector<vector<int>> matrix(n,vector<int>(n));

    for(int i=0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> matrix[i][j];
        }
    }

    cout << searchMatrix(matrix,target);
    return 0;
}