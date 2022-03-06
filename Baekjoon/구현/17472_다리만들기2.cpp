#include<bits/stdc++.h>
using namespace std;
int board[11][11];
int n,m;
int id=1;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int uni[11];
bool visited[11][11];
struct Edge{
    int start;
    int end;
    int cost;
    Edge(int a,int b,int c){
        start = a;
        end = b;
        cost = c;
    }
    bool operator< (const Edge e) const{
        return cost < e.cost;
    }
};
vector<Edge> edges;

void numbering(int x,int y){
    visited[x][y] = true;
    board[x][y] = id;
    queue<pair<int,int>> q;
    q.push({x,y});
    while(!q.empty()){
        pair<int,int> cur = q.front(); q.pop();
        for(int i=0;i<4;i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx >= n || nx < 0 || ny >=m || ny < 0) continue;
            if(visited[nx][ny]) continue;
            if(board[nx][ny] != 0){
                board[nx][ny] = id;
                visited[nx][ny] = true;
                q.push({nx,ny});
            }
        }
    }
    id++;
}

void dfs(int x,int y,int dir,int res,int cur){
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if(nx >= n || nx < 0 || ny >=m || ny < 0) return;
    int next = board[nx][ny];
    if(next == 0){
        dfs(nx,ny,dir,res+1,cur);
    }
    else if(next == cur) return;
    else{
        if(res >= 2){
            edges.push_back({cur,next,res});
            edges.push_back({next,cur,res});
        }
        return;
    }
}

void createBridge(int x,int y,int cur){ // dfs기반으로 
    for(int i=0;i<4;i++){
        dfs(x,y,i,0,cur);
    }
}
int find(int a){
    if(a == uni[a]) return a;
    else return uni[a] = find(uni[a]);
}

void integrate(int a,int b){
    a = find(a);
    b = find(b);
    if(a!=b) uni[a] = b;
}
    
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
        }
    }
  
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j] && board[i][j]) numbering(i,j);
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]) createBridge(i,j,board[i][j]);
        }
    }
    int answer = 0;
    for(int i=1;i<id;i++){
        uni[i] = i;
    }
    sort(edges.begin(),edges.end());
    for(auto it : edges){
        if(find(it.start) != find(it.end)){
            integrate(it.start,it.end);
            answer += it.cost;
        }
    }

    for(int i=2;i<id;i++){
        if(find(1) != find(i)) {
            cout << -1;
            return 0;
        }
    }
    cout << answer;
}
