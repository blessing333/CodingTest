#include<bits/stdc++.h>
using namespace std;
int n,m;
int board[101][101];
bool visited[101][101];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
vector<pair<int,int>> outerCheese;
unordered_map<int,int> hole;
bool checkCondition(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]) return false;
        }
    }
    return true;
}

void findOuterCheese(int x,int y){
    queue<pair<int,int>> q;
    visited[x][y] = true;
    q.push({x,y});
    while(!q.empty()){
        pair<int,int> cur = q.front(); q.pop();
        for(int i=0;i<4;i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(visited[nx][ny] || nx >= n || nx < 0 || ny >= m ||ny<0) continue;
            if(board[nx][ny] == 0){
                q.push({nx,ny});
                visited[nx][ny] = true;
            }
            else if(board[nx][ny] == 1){
                outerCheese.push_back({nx,ny});
                visited[nx][ny] = true;
            }
        }
    }
}
void findHole(int x,int y){
    queue<pair<int,int>> q;
    visited[x][y] = true;
    q.push({x,y});
    hole[m*x+y] = true;
    while(!q.empty()){
        pair<int,int> cur = q.front(); q.pop();
        for(int i=0;i<4;i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(visited[nx][ny] || nx >= n || nx < 0 || ny >= m ||ny<0 || board[nx][ny] == 1) continue;
            if(board[nx][ny] == 0){
                q.push({nx,ny});
                visited[nx][ny] = true;
                int pos = m*nx+ny;
                hole[pos] = true;
            }
        }
    }
    
}
void melting(){
	vector<pair<int,int>> meltingList;
    for(auto it : outerCheese){
        int x = it.first; int y = it.second;
        int cnt = 0;
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
			int pos = m*nx+ny;
            if(board[nx][ny] == 0 && hole[pos] == 0) cnt++;
            if(cnt >= 2){
                meltingList.push_back({x,y});
				continue;
            }
        }
    }

	for(auto it : meltingList){
		board[it.first][it.second] = 0;
	}
}
int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
        }
    }
    int answer = 0;
	int deb = 1;
    while(!checkCondition()){
        findOuterCheese(0,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == 0  && visited[i][j] == 0){
                    findHole(i,j);
				}
            }
        }
        melting();
        fill(&visited[0][0],&visited[0][0]+ 101*101,0);
        outerCheese.clear();
		hole.clear();
        answer++;
    }
    cout << answer;
}