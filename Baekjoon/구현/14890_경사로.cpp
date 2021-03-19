#include<bits/stdc++.h>
using namespace std;
int n,l,cnt=0;
int board[102][102];
bool checked[102][102][2];
int dx[]={1,0};
int dy[]={0,1};

bool check(int x,int y,int dir){
    vector<pair<int,int>> v;
    int nx = x+dx[dir];
    int ny = y+dy[dir];
    if(nx >=n || nx<0 || ny>=n ||ny<0){
        return true;
    }
        
    if(abs(board[nx][ny]-board[x][y]) > 1) return false; //1. 높이 차이가 1이 아닌경우 
    if(board[nx][ny]<board[x][y]){ //왼쪽 방향으로 경사로를 둘 경우
        //cout << nx <<"  " <<ny <<"ㅇㅔ서 실행\n";
        if(dir == 1){
            for(int i=0;i<l;i++){
                if(checked[nx][ny+i][dir] || ny+i >= n) return false;
                if(board[nx][ny+i] != board[nx][ny]) return false;
                v.push_back({nx,ny+i});
            }
            //nx ny부터 ny+l까지 경사로인지 검사
        }
        else if(dir == 0){
            //nx ny부터 nx+l까지 경사로인지 검사
            for(int i=0;i<l;i++){
                if(checked[nx+i][ny][dir] || nx+i >= n) {
                    //cout << "check1\n";
                    return false;
                }
                if(board[nx+i][ny] != board[nx][ny]){
                    //cout << "check2\n";
                    return false;
                }
                v.push_back({nx+i,ny});
            }   
        }
    }
    else if(board[nx][ny]>board[x][y]){
        //cout << nx <<"  " <<ny <<"ㅇㅔ서 실행\n";
        if(dir == 1){
            for(int i=1;i<=l;i++){
                if(checked[nx][ny-i][dir] || ny-i < 0) {
                    //cout << "check 1\n";
                    return false;
                }
                if(board[nx][ny-i] != board[nx][ny-1]) {
                    //cout << "check 2\n";
                    return false;
                }
                v.push_back({nx,ny-i});
            }
            //nx ny부터 ny-l까지 경사로인지 검사
        }
        else if(dir == 0){
            //nx ny부터 nx-l까지 경사로인지 검사
            for(int i=1;i<=l;i++){
                if(checked[nx-i][ny][dir] || nx-i < 0) return false;
                if(board[nx-i][ny] != board[nx-1][ny]) return false;
                v.push_back({nx-i,ny});
            }   
        }
    }
    for(auto it : v){
        checked[it.first][it.second][dir] = true;
    }
    return check(nx,ny,dir);
}

int main(){
    cin >> n >> l;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> board[i][j];
        }
    }
    for(int i=0;i<n;i++){
        if(check(i,0,1)) {
            cnt++;
           //cout <<"first case : "<< i << "  0\n";
        }
    }
    for(int i=0;i<n;i++){
        if(check(0,i,0)) {
            cnt++;
           //cout <<"second case : "<< i << "  0\n";
        }
    }
    cout << cnt;
}