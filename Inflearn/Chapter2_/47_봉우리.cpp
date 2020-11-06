#include<bits/stdc++.h>
using namespace std;
int n,cnt;
int board[50][50];
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
queue<pair<int ,int>> q;
void bfs(int x,int y){
    bool flag=true;
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
        if(board[nx][ny]>board[x][y]) return;
    }
    cnt++;
}
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> board[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            bfs(i,j);
        }
    }
    cout<<cnt;
}
