#include <bits/stdc++.h>

using namespace std;
bool visited[101][101];
int maximum=0;


void bfs(int x, int y,int m , int n,vector<vector<int>> board,int dx[],int dy[]){
    queue<pair<int,int>> q;
    int area=1;    
    visited[x][y] = true;
    q.push({x,y});
    while(!q.empty()){
        pair<int,int> cur = q.front(); q.pop();
        for(int i=0;i<4;i++){
            int nx=cur.first + dx[i];
            int ny=cur.second + dy[i];
            if(nx >= m || nx<0 || ny>=n || ny<0) continue;
            if(visited[nx][ny]) continue;
            if(board[cur.first][cur.second] == board[nx][ny]){
                q.push({nx,ny});
                visited[nx][ny]=true;
                area++;
            }
        } 
    }
    maximum=max(maximum,area);
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    fill(&visited[0][0],&visited[0][0]+101*101,0);
    
    maximum=0;
    vector<int> answer(2);
    int num=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(!visited[i][j] && picture[i][j]>0){
                num++;
                bfs(i,j,m,n,picture,dx,dy);
            }
        }
    }
    answer[0] = num;
    answer[1] = maximum;
    return answer;
}