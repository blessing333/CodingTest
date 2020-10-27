#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++){
        int a; cin >> a; v.push_back(a);
    }

    sort(v.begin(),v.end(),greater<>());
    int rank=0;
    for(int i=0;i<n-1;i++){
        if(v[i]>v[i+1]){
            rank++;
            if(rank==3){
                cout << v[i];
                break;
            }
        }
    }
}