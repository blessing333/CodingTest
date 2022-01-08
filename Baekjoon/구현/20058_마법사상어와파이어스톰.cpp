#include<bits/stdc++.h>
using namespace std;
int board[64][64];
int tmp[64][64];
int n,q;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int tmp2[64][64];
int answer = 0;
int length = 0;
bool visited[64][64];
int bfs(int x,int y){
    visited[x][y] = true;
    queue<pair<int,int>> q;
    q.push({x,y});
    int cnt = 1;
    while(!q.empty()){
        pair<int,int> cur = q.front(); q.pop();
        for(int i=0;i<4;i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx >= length || nx < 0 || ny >= length || ny < 0) continue;
            if(visited[nx][ny] || board[nx][ny] == 0) continue;
            visited[nx][ny] = true;
            q.push({nx,ny});
            cnt++;
        }
    }
    return cnt;
}
void divide(int cnt,int l,int r,int c,int k){
    if(n-cnt == l){
        int row = 1 << l;
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                board[i+r][j+c] = tmp[row-j-1+r][i+c];
            }
        }
        
    }
    else{
        int half = k/2;
        divide(cnt+1,l,r,c,half);
        divide(cnt+1,l,r,c+half,half);
        divide(cnt+1,l,r+half,c,half);
        divide(cnt+1,l,r+half,c+half,half);
    }
    
    
    
}
int main(){
    cin >> n >> q;
    for(int i=0;i< (1<<n);i++){
        for(int j=0;j< (1<<n);j++){
            int a; cin >> a;
            board[i][j] = a;
            tmp[i][j] = a;
        }
    }
    vector<int> v(q);
    for(int i=0;i<q;i++){
        cin >> v[i];
    }

    length = 1 << n;
    int total = 0;
    for(int i=0;i<length;i++){
        for(int j=0;j<length;j++){
            total += board[i][j];
        }
    }

    for(auto it : v){
        divide(0,it,0,0,length);

        for(int i=0;i<length;i++){
            for(int j=0;j<length;j++){
                tmp2[i][j] = board[i][j];
            }
        }

        for(int i=0;i<length;i++){
            for(int j=0;j<length;j++){
                int cnt = 0;
                if(board[i][j] == 0) continue;
                for(int k=0;k<4;k++){
                    int nx = i+ dx[k];
                    int ny = j +dy[k];
                    if(nx >= length || nx < 0 || ny >= length || ny < 0) continue;
                    if(tmp2[nx][ny] > 0) cnt++;
                }
                if(cnt < 3) {
                    board[i][j]--;
                }
            }
        }
        
        for(int i=0;i<length;i++){
            for(int j=0;j<length;j++){
                tmp[i][j] = board[i][j];
            }
        }
        
    }
    
    total = 0;
    for(int i=0;i<length;i++){
        for(int j=0;j<length;j++){
            total += board[i][j];
        }
    }

    for(int i=0;i<length;i++){
        for(int j=0;j<length;j++){
            if(!visited[i][j] && board[i][j] != 0){
                answer = max(answer,bfs(i,j));
            }
        }
    }
    cout << total << "\n" << answer;

    // for(int i=0;i< (1<<n);i++){
    //     for(int j=0;j< (1<<n);j++){
    //         cout << board[i][j] << " ";
    //     }
    //     cout <<"\n";
    // }
    
}
