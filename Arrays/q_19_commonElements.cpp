#include<bits/stdc++.h>
using namespace std;

vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            vector <int> ans;
           int i = 0, j = 0, k = 0;
            while(i < n1 && j < n2 && k < n3) {
                if(A[i] == B[j] && B[j] == C[k]) {
                    if(ans.size() == 0 || ans[ans.size()-1] != A[i]) {
                        ans.push_back(A[i]);
                    }
                    i++; j++; k++;
                }
                
                while(i < n1 && A[i+1] == A[i]) i++;
                while(j < n2 && B[j+1] == B[j]) j++;
                while(k < n3 && C[k+1] == C[k]) k++;
                
                // cout << i << " " << j << " " << k << endl;
                
                if(A[i] < B[j] || A[i] < C[k]) i++;
                if(B[j] < A[i] || B[j] < C[k]) j++;
                if(C[k] < B[j] || C[k] < A[i]) k++;
                
            }
            return ans;
        }
int main(){
    int n1, n2,n3;
    cin >>n1 >> n2 >> n3;

    int arr1[n1], arr2[n2], arr3[n3];
    for(int i=0;i<n1;i++){
        cin >> arr1[i];
    }
    for(int i=0;i<n2;i++){
        cin >> arr2[i];
    }
    for(int i=0;i<n3;i++){
        cin >> arr3[i];
    }
    vector<int> ans = commonElements(arr1,arr2,arr3,n1,n2,n3);
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << ' ';
    }
    return 0;
}