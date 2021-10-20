#include<bits/stdc++.h>
using namespace std;
int n,m;
char board[50][50];
int startX,startY;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int table[50][50][4][4];
struct Info{
    int x,y,d,s;
    Info(int a, int b, int c ,int de){
        x =a; y = b; d = c; s = de;
    }
};

vector<pair<int,int>> destination;
int bfs(){
    queue<Info> q;
    
    for(int i=0;i<4;i++){
        q.push(Info(startX,startY,i,0));
        table[startX][startY][i][0] = 1;
    }

    while(!q.empty()){
        Info info = q.front(); q.pop();
        int dir = info.d;
    
        if(info.s == 3) return table[info.x][info.y][dir][info.s] - 1;
        for(int i=0;i<4;i++){
            if(dir == i) continue;
            int nx = info.x + dx[i];
            int ny = info.y + dy[i];
            int stat = info.s;
            if(nx < 0 || nx >= n || ny < 0 || ny>=m) continue;
            if(board[nx][ny] == '#') continue;
            else if(board[nx][ny] == 'C')  stat|= 1;
            else if(board[nx][ny] == 'K') stat|= 2;
            if(table[nx][ny][i][stat]) continue;
            table[nx][ny][i][stat] = table[info.x][info.y][dir][info.s] +1;
            q.push({nx,ny,i,stat});
        }
    }
    return -1;
}

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
            if(board[i][j] == 'S'){
                startX = i;
                startY = j;
            }
            else if(board[i][j] == 'C') destination.push_back({i,j});
        }
    }

    board[destination[1].first][destination[1].second] = 'K';

    cout << bfs();
}