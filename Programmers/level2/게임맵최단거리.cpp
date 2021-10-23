#include<bits/stdc++.h>
using namespace std;
int visited[101][101];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int solution(vector<vector<int> > maps){
    int r =maps.size();
    int c = maps[0].size();
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            visited[i][j] = -1;
        }
    }
    queue<pair<int,int>> q;
    visited[0][0] = 1;
    q.push({0,0});
    while(!q.empty()){
        pair<int,int> cur = q.front(); q.pop();
        if(cur.first == r-1 && cur.second == c-1) break;
        for(int i=0;i<4;i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if(visited[nx][ny] > -1 || !maps[nx][ny]) continue;
            visited[nx][ny] = visited[cur.first][cur.second] + 1;
            q.push({nx,ny});
        }
    }
    return visited[r-1][c-1];
}