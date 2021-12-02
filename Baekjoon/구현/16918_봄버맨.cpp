#include<bits/stdc++.h>
using namespace std;
int board[200][200];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int r,c,n;
void timePass(){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(board[i][j]) board[i][j]++;
        }
    }
}

void boom(){
    int boardTmp[200][200];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            boardTmp[i][j] = board[i][j];
        }
    }

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(board[i][j] >= 3){
                boardTmp[i][j] = 0;
                for(int dir = 0; dir<4;dir++){
                    int nx = i+dx[dir];
                    int ny = j+dy[dir];
                    if(nx >= r || nx < 0 || ny >= c || ny < 0) continue;
                    if(board[nx][ny]) boardTmp[nx][ny] = 0;
                }
            }
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            board[i][j] = boardTmp[i][j];
        }
    }
}

void trap(){ // 모든 비어있는칸에 폭탄 설치
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(!board[i][j]) board[i][j] =1;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> r >> c >> n;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            char c; cin >> c;
            if(c == 'O') board[i][j] = 2;
            
        }
    }
    int cnt = 2;
    while(cnt <=n){
        if(cnt % 2 == 0) trap();
        else if(cnt %2 == 1) boom();
        timePass();    
        cnt++;
    }


    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(board[i][j]) cout << "O";
            else cout << ".";
        }
    cout << "\n";
    }
    
}