#include<bits/stdc++.h>
using namespace std;
int n,m;
const int MAX = 101 * 100001;
int main(){
    cin >> n;
    cin >> m;
    vector<vector<int>> dist(n+1,vector<int>(n+1,MAX));
    vector<vector<int>> nxt(n+1,vector<int>(n+1));
    for(int i=1;i<=n;i++) dist[i][i] = 0;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b],c);
        nxt[a][b] = b;
    }
    
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dist[i][j] == MAX) cout << 0 <<" ";
            else cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dist[i][j] == 0 || dist[i][j] == MAX){
                cout << 0 << "\n";
                continue;
            }
            vector<int> path;
            int start = i;
            int end = j;
            while(start !=j){
                path.push_back(start);
                start = nxt[start][end];
            }
            path.push_back(end);
            cout << path.size() << " ";
            for(auto it : path) cout << it <<" ";
            cout <<"\n";
        }
    }
    
}