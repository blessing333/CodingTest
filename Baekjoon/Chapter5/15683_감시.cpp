#include<bits/stdc++.h>
using namespace std;
int n,m;
int board[8][8],tmp[8][8],dx[]={-1,0,1,0},dy[]={0,1,0,-1},minimum=INT_MAX;
vector<pair<int,int>> cctv;
void dfs(int x, int y, int dir){ // cctv의 x,y,방향을 입력받아 cctv가 바라보는 방향을 7로 변경
    dir%=4;
    while(1){
        x+=dx[dir];
        y+=dy[dir];
        if(x>=n || x<0 || y>=m || y<0 || tmp[x][y]==6) break;
        if(tmp[x][y]==0){
            tmp[x][y]=7;
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
            if(board[i][j]!=0 && board[i][j]!=6){
                cctv.push_back({i,j});
            }
        }
    }

    for(int i=0;i<(1<<2*cctv.size());i++){
        copy(&board[0][0],&board[0][0]+64,&tmp[0][0]);
        int combi=i;
        for(int j=0;j<cctv.size();j++){
            int dir=combi%4;
            combi/=4;
            int x,y;
            tie(x,y)=cctv[j];

            if(board[x][y] == 1){
                dfs(x,y,dir);
            }

            else if(board[x][y] == 2){
                dfs(x,y,dir);
                dfs(x,y,dir+2);
            }

            else if(board[x][y] == 3){
                dfs(x,y,dir);
                dfs(x,y,dir+1);
            }

            else if(board[x][y] == 4){
                dfs(x,y,dir);
                dfs(x,y,dir+1);
                dfs(x,y,dir+3);
            }

            else{
                dfs(x,y,dir);
                dfs(x,y,dir+1);
                dfs(x,y,dir+2);
                dfs(x,y,dir+3);
            }
        }
        int cnt=0;
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                if(tmp[j][k]==0) cnt++;
            }
        }
        minimum=min(cnt,minimum);
    }

    cout << minimum;
}