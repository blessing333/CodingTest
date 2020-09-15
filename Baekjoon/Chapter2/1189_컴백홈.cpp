#include<bits/stdc++.h>
using namespace std;
int r,c,k,cnt,lv;
int visit[5][5];
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};
char board[5][5];

void dfs(int x,int y,int level){
    if(level==k){
        if(x==0 && y == c-1)
            cnt++;
        return;
    }
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=r || nx<0 ||ny>=c ||ny<0) continue;
        if(visit[nx][ny] || board[nx][ny]=='T') continue;
        visit[nx][ny]=1;
        dfs(nx,ny,level+1);
        visit[nx][ny]=0;
    }
}
int main(){
    cin >> r >> c >> k;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> board[i][j];;
        }
    }
    visit[r-1][0]=1;
    dfs(r-1,0,1);
    cout << cnt;
}