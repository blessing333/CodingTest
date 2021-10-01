#include<bits/stdc++.h>
using namespace std;
int n;
int board[126][126];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int dist[126][126];
queue<pair<int,int>> q;
int main(){
    int cnt =1;
    while(true){
        cin >> n;
        fill(&dist[0][0],&dist[0][0] + 126*126, INT_MAX);
        if(n == 0) break;
        for(int i=0; i<n;i++){
            for(int j=0;j<n;j++){
                cin >> board[i][j];
            }
        }
        dist[0][0] = board[0][0];
        q.push({0,0});
        while(!q.empty()){
            pair<int,int> cur = q.front(); q.pop();
            for(int i=0;i<4;i++){
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];
                int cost = dist[cur.first][cur.second];
                if(nx >= n || nx <0 || ny >= n ||ny <0) continue;
                int nextCost = cost + board[nx][ny];
                if(dist[nx][ny] <= nextCost) continue;
                dist[nx][ny] = nextCost;
                q.push({nx,ny});
            }
        }
        cout << "Problem " << cnt++ <<": "<<dist[n-1][n-1]<<"\n";
    }
}