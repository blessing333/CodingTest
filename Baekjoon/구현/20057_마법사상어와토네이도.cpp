#include<bits/stdc++.h>
using namespace std;
int n;
int board[500][500];
int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};
int answer = 0;
int percent[9] = {1,1,7,7,2,2,10,10,5};
int rx[4][10] = {
    {-1,1,-1,1,-2,2,-1,1,0,0},
    {0,0,1,1,1,1,2,2,3,2},
    {-1,1,-1,1,-2,2,-1,1,0,0},
    {0,0,-1,-1,-1,-1,-2,-2,-3,-2}
};
int ry[4][10] = {
    {0,0,-1,-1,-1,-1,-2,-2,-3,-2},
    {-1,1,-1,1,-2,2,-1,1,0,0},
    {0,0,1,1,1,1,2,2,3,2},
    {-1,1,-1,1,-2,2,-1,1,0,0}
};

void spread(int tx,int ty, int targetX,int targetY,int dir){
    int value = board[targetX][targetY];
    for(int i=0;i<9;i++){
        int nx = tx + rx[dir][i];
        int ny = ty + ry[dir][i];
        int blowSand = (value * percent[i]) /100;
        
        board[targetX][targetY] -= blowSand;
        if(nx >= n || nx < 0 || ny >= n || ny < 0){
            answer += blowSand;
            continue;
        }
        board[nx][ny] +=blowSand;
    }
    int nx = tx + rx[dir][9];
    int ny = ty + ry[dir][9];
    if(nx >= n || nx < 0 || ny >= n || ny < 0){
        answer += board[targetX][targetY];
        board[targetX][targetY] = 0;
        return;
    }
    board[nx][ny] += board[targetX][targetY];
    board[targetX][targetY] = 0;
    
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> board[i][j];
        }
    }
    int tx,ty;
    int cnt = 1;
    int dirChange = 0;
    int dir = 0;
    tx = ty = n/2;
    while(!(tx == 0 && ty == 0)){
        for(int i=0;i<cnt;i++){
            int nx = tx + dx[dir];
            int ny = ty + dy[dir];
            if(nx >= n || nx < 0 || ny >= n || ny <0 ) break;
            spread(tx,ty,nx,ny,dir);
            tx=nx; ty=ny;
            if(tx == 0 && ty == 0) break;
        }
        dirChange++;
        dir = (dir+1)%4;
        if(dirChange== 2){
            dirChange = 0;
            cnt++;
        }
    }
    cout << answer;
}