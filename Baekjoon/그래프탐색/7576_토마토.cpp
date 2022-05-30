#include<bits/stdc++.h>
using namespace std;
int n,m;
int board[1001][1001];
int visited[1001][1001];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

bool checkTomato(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j] == 0)
                return false;
        }
    }
    return true;
}

int main(){
    cin >> m >> n;
    queue<pair<int,int>> q;
    fill(&visited[0][0],&visited[0][0] + 1001 * 1001,-1);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
            if(board[i][j] == 1){
                q.push({i,j});
                visited[i][j] = 0;
            }
        }
    }
    int day = 0;
    
    while(!q.empty()){
        pair<int,int> cur = q.front(); q.pop();
        for(int i=0;i<4;i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m ) continue;
            if(visited[nx][ny] >= 0 || board[nx][ny] == -1) continue;

            q.push({nx,ny});
            board[nx][ny] = 1;
            visited[nx][ny] = visited[cur.first][cur.second] + 1;
            day = max(day,visited[nx][ny]);
        }
    }
    day = checkTomato() ? day :-1;
    cout << day;
}
