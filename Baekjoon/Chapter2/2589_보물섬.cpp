#include<bits/stdc++.h>
using namespace std;

char board[55][55];
int visit[55][55];
int start_visit[55][55];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

queue<pair<int,int>> q;
int n,m,result;

void bfs(int x,int y){
    start_visit[x][y]=1;
    visit[x][y]=0;
    q.push({x,y});
    while(!q.empty()){
        pair<int,int> cur=q.front();q.pop();
        for(int i=0;i<4;i++){
            int nx=cur.first+dx[i];
            int ny=cur.second+dy[i];
            if(nx>=n||nx<0 || ny>=m || ny<0) continue;
            if(visit[nx][ny]==-1 && board[nx][ny]=='L'){
                visit[nx][ny]=visit[cur.first][cur.second]+1;
                q.push({nx,ny});
            }
        }
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            result=max(result,visit[i][j]);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]=='L' && !start_visit[i][j]){
                fill(&visit[0][0],&visit[0][0]+55*55,-1);
                bfs(i,j);
            }
        }
    }
    cout << result;
}