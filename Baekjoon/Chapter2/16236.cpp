#include<bits/stdc++.h>
using namespace std;
int start_x,start_y;
int n,board[20][20],ret,feedCnt,sharkAge=2,dist[20][20];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

queue<pair<int,int>> q;
bool isUpdate=true;
bool visited[20][20];
void logic(int x,int y){
    vector<pair<int,int>> feed;
    vector<pair<int,int>> candi;
    fill(&visited[0][0],&visited[0][0]+400,false);
    fill(&dist[0][0],&dist[0][0]+400,0);
    int minimum=INT_MAX;

    visited[x][y]=true;
    q.push({x,y});
    while(!q.empty()){
        pair<int,int> cur =q.front(); q.pop();
        for(int i=0;i<4;i++){
            int nx=cur.first+dx[i];
            int ny=cur.second+dy[i];
            if(nx>=n || nx < 0 || ny <0 || ny>=n || visited[nx][ny]) continue;
            if(board[nx][ny]>sharkAge) continue;
            q.push({nx,ny});
            visited[nx][ny]=true;
            dist[nx][ny]=dist[cur.first][cur.second]+1;
            if(board[nx][ny]<sharkAge && board[nx][ny]>0){
                feed.push_back({nx,ny});
                if(dist[nx][ny]<minimum) minimum=dist[nx][ny];
            }
        }
    }
    for(auto it : feed){
        if(dist[it.first][it.second]==minimum){
            candi.push_back(it);
        }
    }
    if(candi.size()>1) sort(candi.begin(),candi.end());
    if(candi.size()>0){
        pair<int,int> cur = candi.front();
        start_x=cur.first;
        start_y=cur.second;
        board[cur.first][cur.second]=0;
        feedCnt++;
        ret+=dist[cur.first][cur.second];
        if(feedCnt==sharkAge){
            feedCnt=0;
            sharkAge++;
        }
        isUpdate=true;
    }
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> board[i][j];
            if(board[i][j]==9){
                start_x=i;
                start_y=j;
                board[i][j]=0;
            }
        }
    }
    
    while(isUpdate){
        isUpdate=false;
        logic(start_x,start_y);
    }
    cout << ret;
}