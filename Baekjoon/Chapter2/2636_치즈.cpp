#include<bits/stdc++.h>
using namespace std;
int n,m,num,cnt,anw;
bool visit[100][100];
int board[100][100];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
queue<pair<int,int>> q,cheese;
void bfs(int x, int y){
    q.push({x,y});
    visit[x][y]=true;
    while(!q.empty()){
        pair<int,int> cur=q.front();q.pop();
        for(int i=0;i<4;i++){
            int nx=cur.first+dx[i];
            int ny=cur.second+dy[i];
            if(nx>=n||nx<0||ny>=m||ny<0)continue;
            if(!board[nx][ny]&&!visit[nx][ny]){
                q.push({nx,ny});
                visit[nx][ny]=true;
            }
            else if(board[nx][ny]&&!visit[nx][ny]){
                cheese.push({nx,ny});
                visit[nx][ny]=true;
            }
        }
    }
    cnt++;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
            if(board[i][j]==1)
                num++;
        }
    }
    while(num>0){
        fill(&visit[0][0],&visit[0][0]+100*100,0);
        bfs(0,0);
        anw=cheese.size();
        while(!cheese.empty()){
            pair<int,int> cur=cheese.front();cheese.pop();
            board[cur.first][cur.second]=0;
        }    
        num-=anw;
    }
    
    cout << cnt<<"\n"<<anw;
}