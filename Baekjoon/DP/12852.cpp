#include<bits/stdc++.h>
using namespace std;
int go[1000005];
int d[1000005];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    d[1] = 0;

    for(int i=2 ; i<=n; i++){
        d[i] = d[i-1] + 1;
        go[i] = i-1;
        
        if(i%2 == 0){
            if(d[i/2]+1 < d[i] ){
                d[i] = d[i/2]+1;
                go[i] = i/2;
            }
        }
        
        if(i%3 == 0){
            if(d[i/3]+1 < d[i] ){
                d[i] = d[i/3]+1;
                go[i] = i/3;
            }
        }
    }

    int idx = n;
    cout << d[n]<<"\n";
    while(true){
        cout << idx <<" ";
        if(idx == 1) break;
        idx = go[idx];
    }
}