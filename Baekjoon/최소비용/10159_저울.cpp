#include<bits/stdc++.h>

using namespace std;
int n,m;
int main(){
    cin >> n;
    cin >> m;
    vector<vector<int>> dist(n+1,vector<int>(n+1,101));
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        dist[b][a] = 1;
    }
    for(int i=1;i<=n;i++) dist[i][i] = 0;
    
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j] );
            }
        }
    }
    int answer = 0;
    for(int i=1;i<=n;i++){
        int cnt = 0;
        for(int j=0;j<=n;j++){
            if(i == j) continue;
            if(dist[i][j] != 101 || dist[j][i] != 101) cnt++;
        }
        if(cnt == n-1) cout << 0;
        else cout << n-cnt-1;
        cout <<"\n";
    }
}