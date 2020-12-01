#include<bits/stdc++.h>
using namespace std;
int n,m,xx1,xx2,yy1,yy2,cnt,deb;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
char board[305][305];
bool visited[305][305];
bool isFind;
queue<pair<int,int>> q;
void bfs(int x,int y){
    char tmp[305][305];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            tmp[i][j]=board[i][j];
        }
    }

    visited[x][y]=true;
    q.push({x,y});
    while(!q.empty()){
        pair<int,int>cur= q.front();q.pop();
        if(cur.first==xx2-1 && cur.second==yy2-1){
            isFind=true;
            return;
        }
        
        for(int i=0;i<4;i++){
            int nx=cur.first+dx[i];
            int ny=cur.second+dy[i];
            if(nx>=n || nx<0 || ny>=m || ny<0) continue;
            if(visited[nx][ny]) continue;
            if(board[nx][ny]=='1'){
                tmp[nx][ny]='0';
            }
            else{
                q.push({nx,ny});
                visited[nx][ny]=true;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            board[i][j]=tmp[i][j];
        }
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout << board[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n\n\n";
}
int main(){
    cin >> n >> m;
    cin >> xx1 >> yy1 >> xx2 >> yy2;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
        }
    }
    while(true){
        fill(&visited[0][0],&visited[0][0]+305*305,0);
        //cout << "roop : "<<deb++<<"\n";
        bfs(xx1-1,yy1-1);
        cnt++;
        if(isFind) break;
    }
    cout << cnt;
}