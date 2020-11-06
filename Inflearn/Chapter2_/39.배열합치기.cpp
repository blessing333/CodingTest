#include<bits/stdc++.h>
using namespace std;
int a[100],b[100],idx1,idx2;
int n,m;
vector<int> v;
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    cin >> m;
    for(int i=0;i<m;i++){
        cin >> b[i];
    }

    while(idx1 < n && idx2 < m){
        if(a[idx1]>b[idx2])
            v.push_back(b[idx2++]);
        
        else
            v.push_back(a[idx1++]);
    }

    if(idx1< n){
        while(idx1 < n){
            v.push_back(a[idx1++]);
        }
    }
    else if(idx2 < m){
        while(idx2 < m){
            v.push_back(b[idx2++]);
        }
    }
    for(auto it : v){
        cout << it << " ";
    }
}