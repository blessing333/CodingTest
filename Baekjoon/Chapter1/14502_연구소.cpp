#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,result;
int board[8][8];
int tmp[8][8];
int dx[]={1,0,-1,0};
int dy[]={0,-1,0,1};
bool visit[8][8];
queue<pair<int,int>> q;
vector<pair<int,int>> v,v1,start;

void bfs(){
    for(auto it : start ){
        q.push(it);
        visit[it.first][it.second]=true;
    }
    while(!q.empty()){
        pair<int,int> cur=q.front();q.pop();
        for(int i=0;i<4;i++){
            int nx=cur.first+dx[i];
            int ny=cur.second+dy[i];
            if(nx>=n || nx <0 ||ny>= m || ny<0 ) continue;
            if(!visit[nx][ny]&& tmp[nx][ny]!=1){
                q.push({nx,ny});
                visit[nx][ny]=true;
                tmp[nx][ny]=2;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(tmp[i][j]==0){
                cnt++;
            }
        }
    }
    result=max(result,cnt);
    cnt=0;
    return;
    
}
//원본 board 복사 해야함
void combi(int here){
    if(v1.size()==3){
        copy(&board[0][0],&board[0][0]+64,&tmp[0][0]);
        fill(&visit[0][0],&visit[0][0]+64,false);
        for(auto it : v1){
            tmp[it.first][it.second]=1;
        }
        bfs();
        //cout << "\n";cout << "\n";
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout << tmp[i][j]<<" ";
        //     }
        //     cout << "\n";
        // }

        return;
    }
    for(int i=here+1;i<v.size();i++){
        v1.push_back(v[i]);
        combi(i);
        v1.pop_back();
    }
}

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
            if(board[i][j]==2){
                start.push_back({i,j});
            }
            else if(board[i][j]==0){
                v.push_back({i,j});
            }
        }
    }
    combi(-1);
    cout << result;
}