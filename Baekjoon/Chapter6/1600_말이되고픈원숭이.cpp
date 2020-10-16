#include<bits/stdc++.h>
using namespace std;
struct P{
    int x; int y; int z;
};
int k,r,c,board[200][200],result=-1;
int dist[200][200][31];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int hdx[]={-2,-2,-1,-1,1,1,2,2},hdy[]={-1,1,-2,2,-2,2,-1,1};
queue<P> q;
void bfs(){
    while(!q.empty()){
        P cur=q.front();q.pop();
        int z=cur.z;
        if(cur.x == r-1 && cur.y==c-1){
            result= dist[cur.x][cur.y][cur.z]-1;
            return;
        }
        for(int i=0;i<4;i++){
            int nx=cur.x+dx[i];
            int ny=cur.y+dy[i];
            if(nx>=r || nx<0 || ny>=c || ny<0) continue;
            if(dist[nx][ny][z] || board[nx][ny]) continue;
            q.push({nx,ny,z});
            dist[nx][ny][z]=dist[cur.x][cur.y][z]+1;
        }
        if(z > 0){
            for(int i=0;i<8;i++){
                int nx=cur.x+hdx[i];
                int ny=cur.y+hdy[i];
                if(nx>=r || nx<0 || ny>=c || ny<0) continue;
                if(dist[nx][ny][z-1] || board[nx][ny]) continue;
                q.push({nx,ny,z-1});
                dist[nx][ny][z-1]=dist[cur.x][cur.y][z]+1;
            }
        }
    }
}
int main(){
    cin >> k;
    cin >> c >> r;

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)
            cin >> board[i][j];
    }
    q.push({0,0,k});
    dist[0][0][k]=1;
    bfs();   
    cout << result;
}