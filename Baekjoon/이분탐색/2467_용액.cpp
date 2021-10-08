#include<bits/stdc++.h>
using namespace std;
int n;
vector<long long> v;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++){
        long long a; cin >> a;
        v.push_back(a);
    }
    v.push_back(__LONG_LONG_MAX__);
    int sz = v.size();
    long long answer=0,answer2=0;
    long long minimum = __LONG_LONG_MAX__;

    for(int i=0;i<n-1;i++){
        long long cur = v[i];
        if(cur < 0){
            auto it = lower_bound(v.begin(),v.end(),-cur);
            int idx = it - v.begin();
            long long a = abs(cur + v[idx]);
            long long b = (idx-1 <= i) ? __LONG_LONG_MAX__ : abs(cur + v[idx-1]);
            if(a < minimum || b < minimum){
                answer = cur;
                answer2 = a < b ? v[idx] : v[idx-1];
                minimum = min(a,b);
            }
        }
        else{
            long long b = cur + v[i+1];
            if(b < minimum){
                answer = cur;
                answer2 = v[i+1];
                minimum = b;
            }
        }
    }
    cout << min(answer,answer2) <<" " << max(answer,answer2);
}