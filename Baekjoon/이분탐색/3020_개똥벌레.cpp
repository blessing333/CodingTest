#include<bits/stdc++.h>
using namespace std;
int n,h,minimum=INT_MAX;
vector<int> v,v2;
unordered_map<int,int> m;
void check(int cur){
    int a = v.end() - lower_bound(v.begin(),v.end(),cur);
    int b = lower_bound(v2.begin(),v2.end(),cur)-v2.begin();
    if(minimum >= a+b){
        minimum = a+b;
        m[a+b]++;
    }
}
int main(){
    cin >> n >> h;
    for(int i=0;i<n;i++){
        int a; cin >> a;
        if(i%2 == 0) v.push_back(a);
        else v2.push_back(h-a);
    }
    sort(v.begin(),v.end());
    sort(v2.begin(),v2.end());

    for(int i=1;i<=h;i++){
        check(i);
    }
    cout << minimum <<" "<< m[minimum];
}