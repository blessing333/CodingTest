#include<bits/stdc++.h>
using namespace std;
int n,m;
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};
int result,cnt;
queue<pair<int,int>> q;

int board[500][500];
int visit[500][500];
void bfs(int x , int y){
    int area=1;
    visit[x][y]=1;
    q.push({x,y});
    while(!q.empty()){
        pair<int, int > cur=q.front();q.pop();
        for(int i=0;i<4;i++){
            int nx=cur.first+dx[i];
            int ny=cur.second+dy[i];
            if(nx>=n ||nx<0 ||ny>=m||ny<0)continue;
            if(visit[nx][ny]||!board[nx][ny]) continue;
            visit[nx][ny]=1;
            q.push({nx,ny});
            area=area+1;
        }
    }
    result=max(result,area);
}
int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visit[i][j] && board[i][j]){
                bfs(i,j);
                cnt ++;
            }
        }
    }
    cout << cnt<<"\n";
    cout << result;
}