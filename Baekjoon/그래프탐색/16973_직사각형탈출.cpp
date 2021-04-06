#include<bits/stdc++.h>
using namespace std;
int board[1000][1000];
int n,m,h,w,sr,sc,fr,fc;
int visited[1000][1000];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

bool canMove(int x, int y){
    if(x >= n || x <0 || y>=m || y<0) return false;
    if(board[x][y] || visited[x][y] > -1) return false;
    if(x+h >= n || x +h<0 || y>=m || y<0) return false;
    if(x >= n || x <0 || y+w>=m || y+w<0) return false;
    if(x+h >= n || x +h<0 || y+w>=m || y+w<0) return false;

    for(int i=x;i<=x+h;i++){
        if(board[i][y]) return false;
    }

    for(int i=x;i<=x+h;i++){
        if(board[i][y+w]) return false;
    }
    
    for(int i=y; i<=y+w;i++){
        if(board[x][i]) return false;
    }

    for(int i=y; i<=y+w;i++){
        if(board[x+h][i]) return false;
    }
    
    return true;
}
int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j =0;j<m;j++){
            cin >> board[i][j];
        }
    }
    cin >> h >> w >> sr >> sc >> fr >> fc;
    sr--; sc--; fr--; fc--; h--; w--;
    int answer = -1;
    queue<pair<int,int>> q;
    fill(&visited[0][0],&visited[0][0] + 1000 *1000,-1);
    visited[sr][sc] = 0;
    q.push({sr,sc});
    while(!q.empty()){
        pair<int,int> cur = q.front(); q.pop();
        if(cur.first == fr && cur.second == fc){
            answer = visited[cur.first][cur.second];
            break;
        }
        for(int i=0;i<4;i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(!canMove(nx,ny)) continue;
            visited[nx][ny] = visited[cur.first][cur.second]+1;
            q.push({nx,ny});
        }
    }
    cout << answer;
}