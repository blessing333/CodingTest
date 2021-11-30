#include<bits/stdc++.h>
using namespace std;
int r,c;
int sx,sy,ex,ey,wx=-1,wy=-1;
int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};
char board[51][51];
int visited[51][51][2];
queue<pair<int,int>> water;
int main(){
    cin >> r >> c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> board[i][j];
            if(board[i][j] == 'S'){
                sx = i; sy = j;
            }
            else if(board[i][j] == 'D'){
                ex = i; ey = j;
            }
            else if(board[i][j] == '*'){
                water.push({i,j});
            }
        }
    }

    // for(int i=0;i<r;i++){
    //     for(int j=0;j<c;j++){
    //         for(int k=0;k<2;k++){
    //             visited[i][j][k] = -1;
    //         }
    //     }
    // }


    
    
    while(!water.empty()){
        pair<int,int> cur = water.front(); water.pop();
        for(int i=0;i<4;i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if(visited[nx][ny][0] == 0 && board[nx][ny] == '.'){
                visited[nx][ny][0] = visited[cur.first][cur.second][0]+1;
                water.push({nx,ny});
            }
        }
    }
    
    queue<pair<int,int>> q;
    visited[sx][sy][1] = 0;
    q.push({sx,sy});
    while(!q.empty()){
        pair<int,int> cur = q.front(); q.pop();
        for(int i=0;i<4;i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx >= r || nx < 0 || ny >=c ||ny <0) continue;
            if(visited[nx][ny][1] == 0 && (board[nx][ny] == '.' || board[nx][ny] == 'D')){
                if(visited[nx][ny][0] == 0){
                    visited[nx][ny][1] = visited[cur.first][cur.second][1]+1;
                    q.push({nx,ny});
                }
                else {
                    if(visited[nx][ny][0] > visited[cur.first][cur.second][1]+1){
                        visited[nx][ny][1] = visited[cur.first][cur.second][1]+1;
                        q.push({nx,ny});
                    }
                }
            }
        }
    }

    // cout <<"\n";
    // for(int i=0;i<r;i++){
    //     for(int j=0;j<c;j++){
    //         cout << visited[i][j][0] <<" ";
    //     }
    //     cout << "\n";
    // }

    // cout <<"\n";
    // for(int i=0;i<r;i++){
    //     for(int j=0;j<c;j++){
    //         cout << visited[i][j][1] <<" ";
    //     }
    //     cout << "\n";
    // }

    if(visited[ex][ey][1] == 0) cout << "KAKTUS";
    else cout << visited[ex][ey][1];

}