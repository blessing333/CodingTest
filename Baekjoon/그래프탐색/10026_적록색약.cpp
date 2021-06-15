#include<bits/stdc++.h>
using namespace std;
int n;
bool visited[100][100];
char board[100][100];
char board2[100][100];
int answer=0,answer2=0;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

void bfs(int x,int y, char board[][100]){
    visited[x][y] = true;
    queue<pair<int,int>> q;
    q.push({x,y});
    while(!q.empty()){
        pair<int,int> cur = q.front(); q.pop();
        for(int i=0;i<4;i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx >= n || nx <0 || ny >= n || ny <0) continue;
            if(!visited[nx][ny] && board[cur.first][cur.second] == board[nx][ny]){
                visited[nx][ny] = true;
                q.push({nx,ny});
            }
        }
    }
    
}
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> board[i][j];
            board2[i][j] = board[i][j];
            if(board2[i][j] == 'G') board2[i][j] = 'R';
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!visited[i][j]){
                bfs(i,j,board);
                answer++;
            }
        }
    }
    fill(&visited[0][0],&visited[0][0]+10000,false);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!visited[i][j]){
                bfs(i,j,board2);
                answer2++;
            }
        }
    }
    cout << answer <<" " <<answer2;
}