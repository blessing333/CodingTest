#include<bits/stdc++.h>
using namespace std;
int n,m;
int MAX = 100001 * 101;
int main(){
    cin >> n;
    cin >> m;
    vector<vector<int>> dist(n+1,vector<int>(n+1,MAX));
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b],c);
    }
    for(int i=1;i<=n;i++) dist[i][i] = 0;
    
    for(int k = 1; k <= n; k++ ){
        for(int i=1;i<= n; i++){
            for(int j=1;j<=n;j++){
                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
            }
        }
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(dist[i][j] != MAX) cout << dist[i][j]<< " ";
            else cout << 0 << " ";
        }
        cout <<"\n";
    }
}