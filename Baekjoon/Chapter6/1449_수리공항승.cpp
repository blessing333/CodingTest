#include<bits/stdc++.h>
using namespace std;
int n,l,cnt,dist;
vector<int> v;
int main(){
    cin >> n >> l;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    dist=v[0]+l-1;
    for(int i=1;i<v.size();i++){
        if(v[i]>dist){
            dist=v[i]+l-1;
            cnt++;
        }
    }
    cout << cnt;
}