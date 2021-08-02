#include<bits/stdc++.h>
using namespace std;
int n,m,p;
int answer[10];
char board[1000][1000];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
queue<pair<int,int>> q[10];
int dist[10];
void bfs(int curPlayer){
    int cnt = dist[curPlayer];
    while(!q[curPlayer].empty() && cnt--){
        int sz = q[curPlayer].size();
        while(sz--){
            pair<int,int> cur = q[curPlayer].front(); q[curPlayer].pop();
            for(int i=0;i<4;i++){
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];
                if(nx >= n || nx < 0 || ny >= m || ny <0) continue;
                if(board[nx][ny] == '.'){
                    q[curPlayer].push({nx,ny});
                    board[nx][ny] = '0' + curPlayer;
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> p;
    
    for(int i=0;i<p;i++){
        cin >> dist[i];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char a;
            cin >> a; // 문자형임
            if(a >= '1' && a<='9'){
                a-=1;
                int k = a-'0';
                q[k].push({i,j});
            }
            board[i][j] = a;
            
        }
    }
    int curPlayer = 0;
    int deb = 4;
    //while(deb-- >0){
    while(true){
        bool done = true;
        curPlayer%=p;
        //cout << curPlayer <<"\n";
        bfs(curPlayer);
        for(int i=0;i<p;i++){
            if(!q[i].empty()){
                done = false;
            }
        }
        if(done) break;
        curPlayer++;
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j] != '#' && board[i][j] !='.')
                answer[board[i][j]-'0']++;
        }
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout << board[i][j] <<" ";
    //     }
    //     cout << "\n";
    // }

    for(int i=0;i<p;i++) cout << answer[i] << " ";
}