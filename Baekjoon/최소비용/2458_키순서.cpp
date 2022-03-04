#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    
    vector<vector<int>> dist(n+1,vector<int>(n+1,1001));
    
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        dist[a][b] = 1;
    }
    
    for(int i=1;i<=n;i++){
        dist[i][i] = 1;
    }
    
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
  
    int answer = 0;
    for(int i=1;i<=n;i++){
        int cnt = 0;
        for(int j=1;j<=n;j++){
            if(i == j) continue;
            if(dist[i][j] != 1001 || dist[j][i] != 1001 )cnt++;
        }
        if(cnt == n-1) answer++;
    }
    cout << answer;
}