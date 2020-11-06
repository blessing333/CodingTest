#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int n,m;
int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    cout << lower_bound(v.begin(),v.end(),m)-v.begin()+1;
}