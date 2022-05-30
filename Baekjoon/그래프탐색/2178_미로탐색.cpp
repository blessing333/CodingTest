#include<bits/stdc++.h>
using namespace std;
int n,m;
int board[101][101];
int visited[101][101];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%1d",&board[i][j]);
        }
    }
    fill(&visited[0][0],&visited[0][0] + 101 * 101,-1);
    queue<pair<int,int>> q;
    visited[0][0] = 0;
    q.push({0,0});
    
    while(!q.empty()){
        pair<int,int> cur = q.front(); q.pop();
        if(cur.first == n-1 && cur.second == m-1) break;
        for(int i=0;i<4;i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >=m ) continue;
            if(visited[nx][ny] >= 0 || !board[nx][ny]) continue;

            visited[nx][ny] = visited[cur.first][cur.second] + 1;
            q.push({nx,ny});
        }
    }
    cout << visited[n-1][m-1]+1;
    
    
}