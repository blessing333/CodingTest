#include<bits/stdc++.h>
using namespace std;
int n,m,start_x,start_y,d,ret;
int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
bool board[50][50];
bool visited[50][50];
void bfs(int x, int y){
    
}
bool isDone=false;
int main(){
    cin >> n >> m;
    cin >> start_x >> start_y >> d;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           cin >> board[i][j];
        }
    }
    visited[start_x][start_y]=true;
    ret++;
    while(!isDone){
        bool isMove=false;
        int dir=d;
        for(int i=0;i<4;i++){
            dir=dir-1;
            if(dir==-1) dir=3;
            int nx=start_x+dx[dir];
            int ny=start_y+dy[dir];
            if(!visited[nx][ny] && !board[nx][ny]){
                start_x=nx;
                start_y=ny;
                visited[nx][ny]=true;
                ret++;
                isMove=true;
                d=dir;
                break;
            }
            else if(visited[nx][ny] || board[nx][ny]){
                d=dir;
                if(i==3){
                    int back_x=start_x , back_y=start_y;
                    if(dir==0) back_x+=1;
                    else if(dir==1)  back_y-=1;
                    else if(dir == 2) back_x-=1;
                    else if(dir==3) back_y+=1;
                    if(!board[back_x][back_y]){
                        start_x=back_x;
                        start_y=back_y;
                    }
                    else if(board[back_x][back_y]){
                        isDone=true;
                    }
                }
            }
        }
    }
    // cout << "\n\n";
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout << visited[i][j] <<" ";
    //     }
    //     cout << "\n";
    // }
    cout << ret;
}