#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> v,v2;
    for(int i =0;i<n;i++){
        int a; cin >> a;
        v.push_back(a);
        v2.push_back(a);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int key : v2){
        auto iter = lower_bound(v.begin(),v.end(),key);
        cout << iter - v.begin() <<" " ;
    }
}