#include<bits/stdc++.h>
using namespace std;
char board[8][8];int cnt;
int end_x=0,end_y=7;
//int dx[]={1,0,-1,0,1,1,-1,-1,0};
//int dy[]={0,1,0,-1,1,-1,1,-1,0};
 int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1, 0}; //N NE E SE S SW W NW no
 int dy[] = {0, 1, 1, 1, 0, -1, -1, -1, 0};
int start_x=7,start_y=0;
bool isExit,isDead;

void wallMove(){
    for(int i=7;i>=0;i--){
        for(int j=0;j<8;j++){
            if(i==7){
                board[i][j]='.';
                continue;
            }
            if(board[i][j]=='#'){
                board[i+1][j]='#';
                board[i][j]='.';
            }
        }
    }
}

bool dfs(int x, int y){
    if(board[x][y]=='#'){
        return false;
    }
    for(int i=0;i<9;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=8 ||nx<0 || ny>=8 || ny<0) continue;
        if(board[nx][ny]!='#'){
            if(nx == end_x){
                isExit=true;
                return true;
            }
            char tmp[8][8];
            copy(&board[0][0],&board[0][0]+64,&tmp[0][0]);
            wallMove();
            if(dfs(nx,ny))
                return true;
            copy(&tmp[0][0],&tmp[0][0]+64,&board[0][0]);

        }
    }
    return false;
}

int main(){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cin >> board[i][j];
        }
    }

    if(dfs(start_x,start_y))cout << 1;
    else cout<<0;
}