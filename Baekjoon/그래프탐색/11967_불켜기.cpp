#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int,int>> switchMap[100][100];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int answer = 0;
bool light[100][100];
bool visited[100][100];

bool bfs(){
    fill(&visited[0][0], &visited[0][0] + 10000,false);
    queue<pair<int,int>> q;
    visited[0][0] = true;
    q.push({0,0});
    bool isUpdate = false;
    while(!q.empty()){
        pair<int,int> cur = q.front(); q.pop();
        for(int i=0;i<4;i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx >= n || nx < 0 || ny >= n || ny<0) continue;
            if(!light[nx][ny] || visited[nx][ny]) continue;
            for(auto it : switchMap[nx][ny]){
                if(!light[it.first][it.second]){
                    light[it.first][it.second] = true;
                    isUpdate = true;
                    answer++;
                }
            }
            visited[nx][ny] = true;
            q.push({nx,ny});
        }
    }
    return isUpdate;
}
int main(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int x,y,a,b;
        cin >> x >> y >> a >> b;
        x--; y--; a--; b--;
        switchMap[x][y].push_back({a,b});
    }
    light[0][0] = true;
    answer++;

    for(auto it : switchMap[0][0]){
        if(!light[it.first][it.second]){
            light[it.first][it.second] = true;   
            answer++;
        }
    }

    bool flag = true;
    while(flag){
        flag = bfs();
    }
    cout << answer;
}