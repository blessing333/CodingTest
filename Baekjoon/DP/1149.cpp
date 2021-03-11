#include<bits/stdc++.h>
using namespace std;
int d[1004][4];
int p[1004][4];
int main(){
    int n; cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<4;j++){
            cin >> p[i][j];
        }
    }
    d[1][1] = p[1][1];
    d[1][2] = p[1][2];
    d[1][3] = p[1][3];
    
    for(int i=2;i<=n;i++){
        d[i][1] = min(d[i-1][2],d[i-1][3]) + p[i][1];
        d[i][2] = min(d[i-1][1],d[i-1][3]) + p[i][2];
        d[i][3] = min(d[i-1][1],d[i-1][2]) + p[i][3];
    }
    
    //cout << min({d[n][1],d[n][2],d[n][3]});
    cout << *min_element(d[n],d[n]+3);
    
}