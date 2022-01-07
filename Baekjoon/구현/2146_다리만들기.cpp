#include<bits/stdc++.h>
using namespace std;
int board[100][100];
bool visited[100][100];
bool visited2[100][100];
int n;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
vector<int> area(1);
vector<pair<int,int>> v2;
int answer = 0;
vector<vector<pair<int,int>>> candi(1);

bool spread(int id){
    area[id]++;
    fill(&visited2[0][0],&visited2[0][0] + 100 * 100, 0);
    for(auto it : candi[id]){
        board[it.first][it.second] = id;
        visited2[it.first][it.second] = true;
        for(int i=0;i<4;i++){
            int nx = it.first + dx[i];
            int ny = it.second + dy[i];
            if(nx >=n || nx < 0 || ny >= n || ny < 0 ) continue;
            if(board[nx][ny] == id) continue;
            if(visited2[nx][ny]) continue;
            else if(board[nx][ny] == 0){
                v2.push_back({nx,ny});
                visited2[nx][ny] = true;
            }
            else{
                answer = area[id] + area[board[nx][ny]];
                return true;
            }
        }
    }
    candi[id] = v2;
    v2.clear();
    return false;
}

void logic(int x,int y,int div){
    queue<pair<int,int>> q;
    visited[x][y] = true;
    board[x][y] = div;
    vector<pair<int,int>> v;
    q.push({x,y});
    while(!q.empty()){
        pair<int,int> cur = q.front();q.pop();
        for(int i=0;i<4;i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx >= n || nx < 0 || ny >=n || ny < 0) continue;
            if(visited[nx][ny]) continue;
            if(board[nx][ny] != 0){
                q.push({nx,ny});
                board[nx][ny] = div;
                visited[nx][ny] = true;
            }
            else if(board[nx][ny] == 0){
                v.push_back({nx,ny});
            }
            
        }
    }
    candi.push_back(v);
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> board[i][j];
        }
    }

    int div = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j] != 0 && !visited[i][j]){
                logic(i,j,div);
                div++;
                area.push_back(0);
            }
        }
    }
    
    int sz = candi.size();
    bool result = false;
    while(!result){
        for(int i=1;i<sz;i++){ // 간척 사업
            result = spread(i); // i 번째 섬 간척
            if(result){
                cout << answer;
                break;
            }
        }
    }
}