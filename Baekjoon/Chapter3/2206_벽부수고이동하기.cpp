#include<bits/stdc++.h>
using namespace std;
struct P{
    int x; int y; bool flag;
};
int n,m;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int board[1000][1000];
int dist[1000][1000][2];
queue<P> q;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL); cout.tie(NULL);
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%1d",&board[i][j]);
        }
    }
    
    q.push({0,0,0});
    dist[0][0][0]=1;
    
    while(!q.empty()){
        P cur=q.front(); q.pop();
        for(int i=0;i<4;i++){
            int nx=cur.x+dx[i];
            int ny=cur.y+dy[i];
            bool z=cur.flag;
            if(nx >=n || nx<0 || ny>=m || ny<0) continue;
            if(dist[nx][ny][z]) continue;
            if(!board[nx][ny]){
                dist[nx][ny][z]=dist[cur.x][cur.y][z]+1;
                q.push({nx,ny,z});
            }
            if(board[nx][ny] && !z){
                dist[nx][ny][1]=dist[cur.x][cur.y][z]+1;
                q.push({nx,ny,1});
            }
        }
    }

    if(dist[n-1][m-1][0]==0 && dist[n-1][m-1][1]==0)
        cout << -1;
    else if(dist[n-1][m-1][0]!=0 && dist[n-1][m-1][1]!=0)
        cout << min(dist[n-1][m-1][0], dist[n-1][m-1][1]);
    else
        cout << max(dist[n-1][m-1][0], dist[n-1][m-1][1]);
}