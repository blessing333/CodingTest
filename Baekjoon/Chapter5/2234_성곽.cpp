#include<bits/stdc++.h>
using namespace std;
int n,m,board[50][50],visit[50][50],room,area,result;
int dx[]={0,-1,0,1},dy[]={-1,0,1,0};
queue<pair<int,int>> q;
void bfs(int x,int y){
    visit[x][y]=true;
    q.push({x,y});
    int path=1;
    while(!q.empty()){
        int dir=1;
        pair<int,int> cur = q.front();q.pop();
        for(int i=0;i<4;i++){
            if(!(board[cur.first][cur.second] & dir)){
                int nx=cur.first+dx[i];
                int ny=cur.second+dy[i];
                if(nx>= n || nx< 0 || ny>=m || ny<0) continue;
                if(!visit[nx][ny]){
                    visit[nx][ny]=true;
                    q.push({nx,ny});
                    path++;
                }
            }
            dir=dir<<1;
        }
    }
    area=max(area,path);
}

int main(){
    ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
    cin >> m >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visit[i][j]){
                room++;
                bfs(i,j);
            }
        }
    }
    cout << room <<"\n" << area << "\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int dir=1;
            for(int k=0;k<4;k++){
                if((board[i][j] & dir)){
                    fill(&visit[0][0],&visit[0][0]+2500,0);
                    board[i][j]-=dir;
                    bfs(i,j);
                    board[i][j]+=dir;
                }
                dir*=2;
            }
        }
    }

    cout << area;
    
}