# include<bits/stdc++.h>
using namespace std;
int t,w,h;
char board[1000][1000];
int fireDist[1000][1000];
int dist[1000][1000];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int main(){
    cin >> t;
    while(t-- > 0){
        cin >> w >> h;
        int sx,sy;
        queue<pair<int,int>> fireQ;
        fill(&dist[0][0],&dist[0][0] + 1000*1000,INT_MAX);
        fill(&fireDist[0][0],&fireDist[0][0] + 1000*1000,INT_MAX);
        
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin >> board[i][j];
                if(board[i][j] == '@'){
                    sx = i;
                    sy = j;
                }
                else if(board[i][j] == '*'){
                    fireQ.push({i,j});
                    fireDist[i][j] = 0;
                }
            }
        }
        if(sx >= h-1 || sx <= 0 || sy >= w-1 || sy<=0){
            cout << 1 <<"\n";
            continue;
        }

        while(!fireQ.empty()){
            pair<int,int> cur = fireQ.front(); fireQ.pop();
            for(int i=0;i<4;i++){
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];
                if(nx >= h || nx < 0 || ny >= w || ny<0) continue;
                if(fireDist[nx][ny] != INT_MAX || board[nx][ny] == '#') continue;
                fireDist[nx][ny] = fireDist[cur.first][cur.second] +1;
                fireQ.push({nx,ny});
            }
        }
        queue<pair<int,int>> q;
        dist[sx][sy] = 0;
        q.push({sx,sy});
        int answer = -1;
        bool done = false;
        while(!q.empty()){
            pair<int,int> cur = q.front(); q.pop();
            for(int i=0;i<4;i++){
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];
                if(nx >= h || nx < 0 || ny >= w || ny<0){
                    answer = dist[cur.first][cur.second]+1;
                    done = true;
                    break;
                }
                if(dist[nx][ny] != INT_MAX || board[nx][ny] == '#') continue;
                if(dist[cur.first][cur.second]+1 >= fireDist[nx][ny]) continue;
                dist[nx][ny] = dist[cur.first][cur.second] +1;
                q.push({nx,ny});
            }
            if(done) break;
        }
        if(answer == -1) cout << "IMPOSSIBLE"<<"\n";
        else cout << answer<<"\n";
    }
}