#include<bits/stdc++.h>
using namespace std;
int n,board[16][16],cnt;
int dx[3][3]={
    {0,1,-1},
    {1,1,-1},
    {0,1,1}
};
int dy[3][3]={
    {1,1,-1},
    {0,1,-1},
    {1,0,1}
};
int dstate[3][3]={
    {0,2,-1},
    {0,1,-1},
    {-2,-1,0}
};

struct pipe{
    int x;
    int y;
    int state; //0:가로     1:세로      2:대각선
};
queue<pipe> q;
void bfs(){
    pipe start;
    start.x=0;start.y=1;start.state=0;
    q.push(start);

    while(!q.empty()){
        pipe cur=q.front();q.pop();
        if(cur.x==n-1 && cur.y ==n-1){
            cnt++;
            continue;
        }
       int dir;
        if(cur.state==0){
            dir=2;
        }
        else if(cur.state==1){
            dir=2;
        }
        else if(cur.state==2){
            dir=3;
        }

        for(int i=0;i<dir;i++){
            int nx=cur.x+dx[cur.state][i];
            int ny=cur.y+dy[cur.state][i];
            int nstate=cur.state+dstate[cur.state][i];

            if(nx>=n || ny >=n || nx<0 || ny <0) continue;
            // if(nstate==0 && !board[nx][ny]){
            //     pipe npipe;
            //     npipe.x=nx; npipe.y=ny; npipe.state=nstate;
            //     q.push(npipe);
            // }
            // else if(nstate==1 && !board[nx][ny]){
            //     pipe npipe;
            //     npipe.x=nx; npipe.y=ny; npipe.state=nstate;
            //     q.push(npipe);
            // }
            // else if(nstate==2 && !board[nx][ny] &&!board[nx-1][ny]&& !board[nx][ny-1]){
            //     pipe npipe;
            //     npipe.x=nx; npipe.y=ny; npipe.state=nstate;
            //     q.push(npipe);
            // }
            if((nstate==1 || nstate==0) && !board[nx][ny]){
                //만약 현재 상태가 0,1이고 nx ny이 1이 아니라면
                pipe npipe;
                npipe.x=nx;npipe.y=ny;npipe.state=nstate;
                q.push(npipe);
            }
            else if(nstate==2 && !board[nx][ny] && !board[nx-1][ny] && !board[nx][ny-1]){
                //만약 현재 상태가 2이고 nx ny와 그 왼쪽, 위가 1이 아니라면
                pipe npipe;
                npipe.x=nx;npipe.y=ny;npipe.state=nstate;
                q.push(npipe);
            }

        }
    }
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> board[i][j];
        }
    }
    bfs();
    cout << cnt;
}