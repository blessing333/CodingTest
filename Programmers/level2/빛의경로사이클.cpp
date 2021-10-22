#include <bits/stdc++.h>

using namespace std;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
bool visited[501][501][4];    
struct Info{
    int x,y,dir;
};

int bfs(int x,int y,int d,vector<string> grid){
    int r = grid.size();
    int c = grid[0].size();
    queue<Info> q;
    visited[x][y][d] = true;
    q.push({x,y,d});
    int cnt = 1;
    while(!q.empty()){
        Info cur = q.front(); q.pop();
        int nx = cur.x + dx[cur.dir];
        int ny = cur.y + dy[cur.dir];
        int nd = cur.dir;
        if(nx < 0 ) nx = r-1;
        if(nx >= r) nx = 0;
        if(ny < 0) ny = c-1;
        if(ny >= c) ny = 0;
        
        if(grid[nx][ny] == 'L') nd--;
        else if(grid[nx][ny] == 'R') nd++;
        
        if(nd == -1) nd = 3;
        else if(nd == 4) nd = 0;
        
        if(visited[nx][ny][nd]) break;
        visited[nx][ny][nd] = true;
        cnt++;
        q.push({nx,ny,nd});
    }
    return cnt;
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    int r = grid.size();
    int c = grid[0].size();
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            for(int k=0;k<4;k++){
                if(visited[i][j][k]) continue;
                int result = bfs(i,j,k,grid);
                answer.push_back(result);
            }   
        }
    }
    sort(answer.begin(),answer.end());
    return answer;
}