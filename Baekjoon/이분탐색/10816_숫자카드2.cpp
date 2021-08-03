#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    cin >> n;
    vector<int> v,v2;
    for(int i=0;i<n;i++){
        int a; cin >> a;
        v.push_back(a);
    }
    cin >> m;
    for(int i=0;i<m;i++){
        int a; cin >> a;
        v2.push_back(a);
    }
    sort(v.begin(),v.end());
    for(int key : v2){
        auto high = upper_bound(v.begin(),v.end(),key);
        auto low = lower_bound(v.begin(),v.end(),key);
        cout << high - low << " ";
    }
}