#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n;
    vector<int> v;
    vector<int> v2;
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
        bool result = binary_search(v.begin(),v.end(),key);
        cout << result <<"\n";
    }
}