#include<bits/stdc++.h>
using namespace std;
int m,n;
vector<int> v;
bool check(int target,int sz){
    int cnt = 0;
    for(int i = sz-1;i>=0;i--){
        if(v[i] < target || cnt >= m) break;
        cnt = cnt + (v[i] / target);
    }
    return cnt >= m;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> m >> n;
    
    for(int i=0;i<n;i++){
        int a; cin >> a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    int sz = v.size();
    int left = 1;
    int right = v[v.size()-1];
    while(left <= right){
        int mid = (left +right) / 2;
        if(check(mid,sz)) left = mid + 1;
        else right = mid -1;
    }
    cout << right; 
}