#include<bits/stdc++.h>
using namespace std;
int n,m,e;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int board[20][20];
map<int,int> client;
int visited[20][20];
int start_x,start_y;

int selectClient(){
    int minDist=INT_MAX;
    int minX,minY;
    for(auto it : client){ //태울 승객을 정함
        int pos = it.first;
        int r = pos/n;
        int c = pos%n;
        int dist = visited[r][c];
        if(dist == -1){
            return -1;
        }
        if(minDist > dist){
            minDist = dist;
            minX = r; minY=c;
        }
        else if(minDist == dist){
            if(minX > r){
                minDist = dist;
                minX = r; minY=c;
            }
            else if(minX == r){
                if(minY > c){
                    minDist = dist;
                    minX = r; minY=c;
                }
            }
        }
    }
    return minX*n+minY;
}

void bfs(int x,int y){
    queue<pair<int,int>> q;
    visited[x][y] = 0;
    q.push({x,y});
    while(!q.empty()){
        pair<int,int> cur = q.front();q.pop();
        for(int i=0;i<4;i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx >= n || nx <0 || ny >= n || ny<0) continue;
            if(visited[nx][ny] > -1) continue;
            if(board[nx][ny] != 1){
                q.push({nx,ny});
                visited[nx][ny] = visited[cur.first][cur.second] +1;
            }
        }
    }
    
}
int main(){
    cin >> n >> m >> e;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> board[i][j];
        }
    }
    cin >> start_x >> start_y;
    start_x--; start_y--;
    for(int i=0;i<m;i++){
        int a,b,c,d;
        cin >> a >> b >> c >>d;
        int pos = (a-1)*n+(b-1);
        int des = (c-1)*n+(d-1);
        client[pos] = des;
    }
    bool fail = false;
    int deb = 1;
    while(client.size() > 0){
    //while(deb-->0){
        fill(&visited[0][0],&visited[0][0]+400,-1);
        bfs(start_x,start_y); // 1.각 승객들의 최소 거리를 구하고
        int clientPos = selectClient(); // 태울 승객을 구함
        if(clientPos == -1){
            fail = true;
            break;
        }

        int clientX = clientPos/n;
        int clientY = clientPos%n;
        int dist = visited[clientX][clientY];
        e-=dist;

        start_x=clientX; start_y=clientY;

        fill(&visited[0][0],&visited[0][0]+400,-1);
        bfs(start_x,start_y);
        int destPos = client[clientPos];
        int destX = destPos / n;
        int destY = destPos % n;
        int destDist = visited[destX][destY];
        e-=destDist;
        if(e<0){
            fail = true;
            break;
        }
        e=e+destDist*2;
        
        start_x=destX; start_y=destY;
        client.erase(clientPos);
    }
    if(fail) cout << -1;
    else cout << e;
}