#include<bits/stdc++.h>
using namespace std;
int n,m,board[50][50],dist[50][50],minimum=INT_MAX;
bool success=false;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
vector<pair<int,int>> v;
vector<pair<int,int>> candi;

void bfs(){
    int tmp[50][50];
    copy(&board[0][0],&board[0][0]+2500,&tmp[0][0]);
    fill(&dist[0][0],&dist[0][0]+2500,-1);
    queue<pair<int,int>> q;
    for(auto it : candi){
        q.push(it);
        dist[it.first][it.second]=0;
    }
    
    while(!q.empty()){
        pair<int,int> cur = q.front(); q.pop();
        int x=cur.first; int y=cur.second;
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=n || ny>=n || nx<0 || ny<0) continue;
            if(dist[nx][ny]>-1 || tmp[nx][ny]==1) continue;
            if(tmp[nx][ny]!=2)
                tmp[nx][ny]=3;
            dist[nx][ny]=dist[x][y]+1;
            q.push({nx,ny});
        }
    }
    bool isFail=false;
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(tmp[i][j]==0){
                return;
            }
            if(tmp[i][j]!=2 && dist[i][j] >=cnt){
                cnt=dist[i][j];
            }
        }
    }
    success=true;
    minimum=min(minimum,cnt);
}

void combi(int here){
    if(candi.size()==m){
        bfs();
        return;
    }
    for(int i=here+1;i<v.size();i++){
        candi.push_back(v[i]);
        combi(i);
        candi.pop_back();
    }
}

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> board[i][j];
            if(board[i][j] == 2){
                v.push_back({i,j});
            }
        }
    }
    combi(-1);
    cout << (success?minimum:-1);
}