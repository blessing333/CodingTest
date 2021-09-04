#include<bits/stdc++.h>
using namespace std;
int dx[] = {-1,-1,0,1,1,1,0,-1};
int dy[] = {0,-1,-1,-1,0,1,1,1};

int answer = 0;
struct Fish{
    int id;
    int x;
    int y;
    int dir;
    bool isAlive;
    Fish(){}
    Fish(int a,int r,int c,int b){
        id = a;
        x = r;
        y = c;
        dir = b;
        isAlive = true;
    }
};

void func(int board[4][4],map<int,Fish> fish,int sum,int x,int y){ // 상어가 n만큼 이동했을때 먹을 수 있는 물고기의 수
    int boardTmp[4][4];
    map<int,Fish> fishTmp;
    copy(&board[0][0],&board[0][0] + 16, &boardTmp[0][0]);
    copy(fish.begin(),fish.end(),(inserter(fishTmp,fishTmp.begin())));
    
    //eat
    int id = boardTmp[x][y];
    sum += id;
    boardTmp[x][y] = -1;
    fishTmp[id].isAlive = false;
    int shark_dir = fishTmp[id].dir;
    if(answer < sum) answer = sum;

    // fish move
    for(auto it : fishTmp){
        if(!it.second.isAlive) continue;
        int dirO = it.second.dir;
        int curX = it.second.x;
        int curY = it.second.y;
        for(int i=0;i<8;i++){
            int dir = dirO + i;
            dir = dir % 8;
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];
            if(nx == x && ny == y) continue;
            if(nx >= 4 || nx < 0 || ny >=4 || ny <0) continue;
            
            int curId = boardTmp[curX][curY];
            int nextId = boardTmp[nx][ny];
            if(nextId != -1){ //다른 생선이 있으면
                boardTmp[nx][ny] = curId;
                boardTmp[curX][curY] = nextId;
                fishTmp[nextId] = Fish(nextId,curX,curY,fishTmp[nextId].dir);
                fishTmp[curId] = Fish(curId,nx,ny,dir);
            }
            else if(nextId == -1){ //다른 생선이 없으면
                boardTmp[nx][ny] = curId;
                boardTmp[curX][curY] = -1;
                fishTmp[curId] = Fish(curId,nx,ny,dir);
            }
            break;
        }
    }
   
    // shark move
    for(int i=1;i<=3;i++){
        int nx = x + dx[shark_dir] * i;
        int ny = y + dy[shark_dir] * i;
        if(nx >= 4 || nx < 0 || ny >= 4 || ny < 0) break;
        if(boardTmp[nx][ny] != -1) func(boardTmp,fishTmp,sum,nx,ny);
    }    
}

int main(){
    int board[4][4];
    map<int,Fish> fish;
    for(int i=0;i<4;i++){
        int a,b;
        for(int j=0;j<4;j++){
            cin >> a >> b;
            b--;
            fish.insert({a,Fish(a,i,j,b)});
            board[i][j] = a;
        }
    }
    func(board,fish,0,0,0);
    cout << answer;
}