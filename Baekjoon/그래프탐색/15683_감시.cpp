#include<bits/stdc++.h>
using namespace std;
struct Info{
    int x;
    int y;
    int type;
    Info(int a,int b, int c){
        x = a;
        y =b;
        type = c;
    }
};
int n,m;
int answer = INT_MAX;
int board[9][9];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int tmp[9][9];
bool visited[9][9];
vector<int> v; // 회전 수
vector<Info> cctv; // cctv 번호

void upd(int x,int y,int dir){
    dir %= 4;
    while(true){
        x += dx[dir];
        y += dy[dir];
        if(x >= n || x < 0 || y >= m || y < 0 || tmp[x][y] == 6) return;
        if(tmp[x][y] != 0) continue;
        tmp[x][y] = 7;
    }

}

void logic(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            tmp[i][j] = board[i][j];
            visited[i][j] = false;
        }
    }

    for(int i=0;i<cctv.size();i++){
        int dir = v[i];
        Info target = cctv[i];
        if(target.type == 1){
            upd(target.x,target.y,dir);
        }
        else if(target.type == 2){
            upd(target.x,target.y,dir);
            upd(target.x,target.y,dir+2);
        }
        else if(target.type == 3){
            upd(target.x,target.y,dir);
            upd(target.x,target.y,dir+1);
        }
        else if(target.type == 4){
            upd(target.x,target.y,dir);
            upd(target.x,target.y,dir+1);
            upd(target.x,target.y,dir+2);
        }
        else if(target.type == 5){
            upd(target.x,target.y,dir);
            upd(target.x,target.y,dir+1);
            upd(target.x,target.y,dir+2);
            upd(target.x,target.y,dir+3);
        }
    }

    int ret = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(tmp[i][j] == 0)
                ret++;
        }
    }
    answer = min(answer,ret);
}

void dfs(){
    if(v.size() == cctv.size()){
        logic();
        return;
    }
    else{
        for(int i=0;i<4;i++){
            v.push_back(i);
            dfs();
            v.pop_back();
        }
    }

}
int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
            if(board[i][j] != 0 && board[i][j] != 6){
                cctv.push_back({i,j,board[i][j]});
            }
        }
    }
    dfs();
    cout << answer;
    
}
