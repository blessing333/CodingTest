#include<bits/stdc++.h>
using namespace std;
int n,l,result;
vector<pair<int ,int>> v;
int main(){
    cin >> n >> l;
    for(int i=0;i<n;i++){
        pair<int,int> p;
        cin >> p.first >> p.second;
        v.push_back(p);
    }
    sort(v.begin(),v.end());

    for(int i=0;i<v.size();i++){ 
        int cnt=0;
        int dist=v[i].second-v[i].first;
        int a=dist/l;
        int b=dist%l;
        cnt+=a;
        if(b>0)cnt++;
        result+=cnt;
        if(i+1<v.size() && v[i].first+(l*cnt)>v[i+1].first){
            v[i+1].first=v[i].first+(l*cnt);
        }
    }
    cout << result;
}