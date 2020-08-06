
#include<bits/stdc++.h>
using namespace std;
int m,n,h;
int board[102][102][102];
int dist[102][102][102];
int dx[6]={1,0,-1,0,0,0};
int dy[6]={0,1,0,-1,0,0};
int dz[6]={0,0,0,0,1,-1};
struct p {
    int x,y,z;
};
queue<p> q;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> m >> n >> h;
    for(int i=0;i<h;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                cin >> board[i][j][k];
                if(board[i][j][k]==1){
                    q.push({i,j,k});
                }
                if(board[i][j][k]==0)
                    dist[i][j][k]=-1;
            }
        }
    }

    while(!q.empty()){
        p cur=q.front();q.pop();
        for(int i=0;i<6;i++){
            int nx=cur.x+dx[i];
            int ny=cur.y+dy[i];
            int nz=cur.z+dz[i];
            if(nx>=h||nx<0||ny>=n||ny<0||nz>=m||nz<0) continue;
            if(dist[nx][ny][nz]>=0) continue;
            dist[nx][ny][nz]=dist[cur.x][cur.y][cur.z]+1;
            q.push({nx,ny,nz});
        }
    }
    int result =0;
    for(int i=0;i<h;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                if(dist[i][j][k]==-1){
                    cout << -1;
                    return 0;
                }
                result=max(result,dist[i][j][k]);
            }   
        }
    }
    cout << result;   
}