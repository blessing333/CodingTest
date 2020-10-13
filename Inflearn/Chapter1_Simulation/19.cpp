#include<bits/stdc++.h>
using namespace std;
int n,cnt;
vector<int> v;
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        int a; cin >> a; v.push_back(a);
    }
    int max=v[n-1];
    for(int i=n-2;i>=0;i--){
        if(v[i]>max){
            max=v[i];
            cnt++;
        }
    }
    cout << cnt;
}