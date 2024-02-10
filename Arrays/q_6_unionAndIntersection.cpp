#include<bits/stdc++.h>
using namespace std;

vector<int> intersectionArray(int a[],int b[],int n,int m){
    int i = 0;
    int j = 0;
    vector<int> interArr;
    while(i<n && j<m){
        if(a[i] == b[j]){
            if(interArr.empty()){
                interArr.push_back(a[i]);
            }
            else if(interArr.back() != a[i]){
                interArr.push_back(a[i]);
            }
            i++;
        }
        else if(a[i] < b[j]){
            i++;
        }
        else{
            j++;
        }
    }
    return interArr;
}
vector<int> unionArray(int a[],int b[],int n,int m){
    int i = 0;
    int j = 0;
    vector<int> unionArr;
    while(i<n && j<m){
        if(a[i] <= b[j]){
            if(unionArr.empty() || unionArr.back() != a[i]){
                unionArr.push_back(a[i]);
            }
            i++;
        }
        else{
            if(unionArr.empty() || unionArr.back() != b[j]){
                unionArr.push_back(b[j]);
            }
            j++;
        }
    }
    while(j<m){
        if(unionArr.empty() || unionArr.back() != b[j]){
            unionArr.push_back(b[j]);
        }
        j++;
    }
    while(i<n){
        if(unionArr.empty() || unionArr.back() != a[i]){
            unionArr.push_back(a[i]);
        }
        i++;
    }

    return unionArr;
    

}
int main(){
    int n ,m;
    cin >>n >> m;

    int a[n],b[m];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<m;i++){
        cin >> b[i];
    }

    vector<int> unionArr = unionArray(a,b,n,m);
    for(int i =0;i<unionArr.size();i++){
        cout << unionArr[i] << ' ';
    }
    cout << endl;

    vector<int> interArr = intersectionArray(a,b,n,m);
    for(int i =0;i<interArr.size();i++){
        cout << interArr[i] << ' ';
    }
    
    return 0;
}