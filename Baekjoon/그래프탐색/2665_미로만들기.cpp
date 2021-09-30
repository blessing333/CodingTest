#include<bits/stdc++.h>
using namespace std;
int n;
int board[51][51];
int dist[51][51];
int dx[] ={1,0,-1,0};
int dy[] = {0,1,0,-1};
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        for(int j=0;j<n;j++) {
            board[i][j] = s[j]-'0';
            dist[i][j] = INT_MAX;
        }
    }
    dist[0][0] = 0;
    queue<pair<int,int>> q;
    int answer = 0;
    q.push({0,0});
    while(!q.empty()){
        pair<int,int> cur = q.front(); q.pop();
        for(int i=0;i<4;i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            int cnt = dist[cur.first][cur.second];
            if(nx >= n || nx < 0 || ny >= n || ny < 0) continue;
            if(dist[nx][ny] <= cnt) continue;
            if(board[nx][ny] == 0) cnt++;
            dist[nx][ny] = cnt;
            q.push({nx,ny});
        }
    }
    cout << dist[n-1][n-1];
}