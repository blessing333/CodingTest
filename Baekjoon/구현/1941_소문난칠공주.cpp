#include<bits/stdc++.h>
using namespace std;
char board[5][5];
int answer = 0;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
vector<int> v;
bool visited[5][5];
bool selected[5][5];
bool check[25];
int cnt;

int bfs(int r,int c){
    queue<pair<int,int>> q;
    fill(&visited[0][0],&visited[0][0] + 25 , false);

    int result = 1;
    visited[r][c] = true;
    q.push({r,c});

    while(!q.empty()){
        pair<int,int> cur = q.front(); q.pop();
        for(int i=0;i<4;i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx < 0 || nx >= 5 || ny < 0 ||ny >= 5) continue;
            if(!selected[nx][ny] || visited[nx][ny]) continue;
            q.push({nx,ny});
            visited[nx][ny] = true;
            result++;
        }
    }
    return result;
}

void permu(int here,int yoon){
    if(yoon >= 4)
        return;
    if(v.size() == 7){
        for(auto it : v){
            int r = it/5;
            int c = it%5;
            selected[r][c] = true;
        }
        int pos = v[0];
        int r = pos/5;
        int c = pos%5;
        int result = bfs(r,c);
        fill(&selected[0][0],&selected[0][0] + 25,0);
        if(result == 7) answer++;
        return;
    }
    
    else{
        for(int i=here+1;i<25;i++){
            int cnt= yoon;
            int r = i/5;
            int c = i%5;
            if(board[r][c] == 'Y') cnt++;
            v.push_back(i);
            permu(i,cnt);
            v.pop_back();
        }
    }
}

int main(){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin >> board[i][j];
        }
    }
    
    permu(-1,0);
    cout << answer;
}