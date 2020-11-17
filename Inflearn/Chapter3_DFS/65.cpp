#include<bits/stdc++.h>
using namespace std;

int board[7][7],dx[]={1,0,-1,0},dy[]={0,1,0,-1},cnt;
bool visit[7][7];

void dfs(int x, int y){
    if(x==6 && y==6){
        cnt++;
        return;
    }
    else{
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx >=7 || nx<0 || ny>=7 || ny<0) continue;
            if(!board[nx][ny] && !visit[nx][ny]){
                visit[nx][ny]=true;
                dfs(nx,ny);
                visit[nx][ny]=false;
            }
        }
    }
}

int main(){
    for(int i=0;i<7;i++){
        for(int j=0;j<7;j++){
            cin >> board[i][j];
        }
    }
    visit[0][0]=true;
    dfs(0,0);
    cout << cnt;
}
