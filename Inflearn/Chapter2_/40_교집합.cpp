#include <bits/stdc++.h>
using namespace std;
int n,m,p1,p2;
vector<int> v,v2,v3;
int main(){
    cin >> n;
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
    sort(v2.begin(),v2.end());

    while(p1< n && p2 < m){
        if(v[p1]>v2[p2]) p2++;
        else if(v[p1]<v2[p2]) p1++;
        else{
            v3.push_back(v[p1]);
            p1++;
            p2++;
        }
    }
    for(auto it : v3){
        
        cout << it << " ";
    }
}