#include<bits/stdc++.h>
using namespace std;

int n,m,k,cnt,area,tmp;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int board[505][505];
int visit[505][505];
queue<pair<int,int>> q;

void bfs(int x,int y){
    tmp=1;
    visit[x][y]=1;
    q.push({x,y});
    while(!q.empty()){
        pair<int,int> cur=q.front();q.pop();
        for(int i=0;i<4;i++){
            int nx=cur.first+dx[i];
            int ny=cur.second+dy[i];
            if(nx>=n||nx<0||ny>=m||ny<0)continue;
            if(visit[nx][ny]==0 && board[nx][ny]==1){
                visit[nx][ny]=1;
                q.push({nx,ny});
                tmp++;
            }
        }
    }
    if(area<tmp)
        area=tmp;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> k;
            board[i][j]=k;
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visit[i][j]==0 && board[i][j]==1){
                bfs(i,j);
                cnt++;
            }
        }
    }

    cout << cnt << "\n";
    cout << area;
}