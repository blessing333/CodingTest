#include<bits/stdc++.h>
using namespace std;
int dx[] = {1,0,-1,0,0,0};
int dy[] = {0,1,0,-1,0,0};
int dz[] = {0,0,0,0,1,-1};
struct Pos{
    int x;int y; int z;
    Pos(int a,int b, int c){
        x =a; y=b; z=c;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while(true){
        int answer = -1;
        char board[30][30][30];
        bool visited[30][30][30];
        
        
        int l,r,c,sx,sy,sz,ex,ey,ez;
        cin >> l >> r >> c;
        if(l == 0 && r == 0 && c == 0) break;

        for(int i=0;i<l;i++){
            for(int j=0;j<r;j++){
                for(int k=0;k<c;k++){
                    visited[i][j][k] = false;
                }
            }
        }
        
        for(int i=0;i<l;i++){
            for(int j=0;j<r;j++){
                for(int k=0;k<c;k++){
                    cin >> board[i][j][k];
                    if(board[i][j][k] == 'S'){
                        sx = j; sy=k; sz=i;
                    }
                    else if(board[i][j][k] == 'E'){
                        ex = j; ey = k; ez = i;
                    }
                }
            }
        }

        queue<Pos> q;
        visited[sz][sx][sy] = true;
        q.push(Pos(sx,sy,sz));
        int dist = 1;
        bool done = false;

        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                Pos cur = q.front();q.pop();
                for(int i=0;i<6;i++){
                    int nx = cur.x + dx[i];
                    int ny = cur.y + dy[i];
                    int nz = cur.z + dz[i];
                    if(nx < 0 || nx >= r || ny >= c || ny < 0 ||nz >= l || nz < 0 ) continue;
                    if(board[nz][nx][ny] == 'E'){
                        answer = dist;
                        done = true;
                        break;
                    }
                    if(board[nz][nx][ny] != '.' || visited[nz][nx][ny]) continue;
                    visited[nz][nx][ny] = true;
                    q.push(Pos(nx,ny,nz));
                }
                if(done) break;
            }
            if(done) break;
            dist++;
        }
        if(answer != -1) cout << "Escaped in " << answer <<" minute(s).\n";
        else cout << "Trapped!\n";

        // for(int i=0;i<l;i++){
        //     for(int j=0;j<r;j++){
        //         for(int k=0;k<c;k++){
        //             cout << visited[i][j][k];
        //         }
        //         cout << "\n";
        //     }
        //     cout << "\n";
        // }

    }
}