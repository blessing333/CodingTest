#include<bits/stdc++.h>
using namespace std;
int tc;
vector<int> v,v2;

void solve(){
    int sum=0;
    sort(v.begin(),v.end());
    sort(v2.begin(),v2.end());
    for(int i=0;i<v2.size();i++){
        sum+=(v.end()-upper_bound(v.begin(),v.end(),v2[i]));  
    }
    cout << sum<<"\n";
}
int main(){
    cin >> tc;
    for(int i=0;i<tc;i++){
        int n,m;
        cin >> n >> m;
        for(int j=0;j<n;j++){
            int a; cin >> a; v.push_back(a);
        }
        for(int k=0;k<m;k++){
            int a;
            cin >>a;
            v2.push_back(a);
        }
        solve();
        v.clear();v2.clear();
    }
}