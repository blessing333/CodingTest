#include<bits/stdc++.h>
using namespace std;
long long n,m;
vector<long long> v;
bool check(long long target,int sz){
    long long sum = 0;
    for(int i=sz-1;i>=0;i--){
        if(v[i] <= target || sum >= m) break;
        sum += v[i] - target;
    }
    return sum >= m;
}
int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        long long a; cin >> a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    long long sz = v.size();
    long long left = 1;
    long long right = v[sz-1];

    while(left <= right){
        long long mid = (left + right) / 2;
        if(check(mid,sz)) left = mid + 1;
        else right = mid -1;
    }
    cout << right;
}