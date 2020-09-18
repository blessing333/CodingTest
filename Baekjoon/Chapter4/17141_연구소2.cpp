#include<bits/stdc++.h>
using namespace std;
int n,m, board[50][50],tmp[50][50],result=987654321,cnt;
bool isMinus=true;
bool visit[50][50];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
queue<pair<int,int>> q;
vector<pair<int,int>> v,v1;
void bfs(){
    int level=0;
    bool isZero=false;
    for(auto it :v1){
        q.push(it);
        visit[it.first][it.second]=true;
    }
    while(!q.empty()){
        int size=q.size();
        while(size--){
            pair<int,int> cur =q.front();q.pop();
            for(int i=0;i<4;i++){
                int nx=cur.first+dx[i];
                int ny=cur.second+dy[i];
                if(nx>=n || nx <0 || ny >=n || ny<0) continue;
                if(!visit[nx][ny] && tmp[nx][ny]!=1){
                    q.push({nx,ny});
                    visit[nx][ny]=true;
                    tmp[nx][ny]=2;
                }
            }
            cout<<"level : "<<level<<"\n";
            cout<<"size : "<<q.size()<<"\n";
        }
        level++;
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(tmp[i][j]==0){
                isZero=true;
                break;
            }
        }
    }
    if(!isZero){
        isMinus=false;
        result=min(result,level-1);
    }
}

void combi(int here){
    if(v1.size()==m){
        copy(&board[0][0],&board[0][0]+2500,&tmp[0][0]);
        fill(&visit[0][0],&visit[0][0]+2500,false);
        bfs();
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
        for(int j=0;j<n;j++){
            cin >> board[i][j];
            if(board[i][j]==2){
                v.push_back({i,j});
            }
        }
    }
    combi(-1);
    if(isMinus){
        cout << "-1";
    }
    else
        cout << result;
}