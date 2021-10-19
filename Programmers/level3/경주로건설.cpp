#include <bits/stdc++.h>

using namespace std;
struct Info{
    int x,y,dir,cost;
    Info(int a,int b,int c,int d){
        x =a; y =b; dir =c; cost = d;
    }
    bool operator> (const Info &a) const{
        return cost > a.cost;
    }
};

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int direc[] = {0,1,0,1}; // up down == 0, left right ==1
bool visited[26][26];
int costTable[26][26][4];

int solution(vector<vector<int>> board) {
    int sz = board.size();
    for(int i=0;i<4;i++){
        for(int j=0;j<sz;j++){
            for(int k=0;k<sz;k++){
                costTable[j][k][i] = INT_MAX;
            }
        }
    }
    
    
    priority_queue<Info,vector<Info>,greater<Info>> q;
    //queue<Info> q;
    for(int i=0;i<4;i++){
        costTable[0][0][i] = 0;
        q.push(Info(0,0,i,0));
    }
    
        
    while(!q.empty()){
        Info info = q.top(); q.pop();
        //Info info = q.front(); q.pop();
        int prevDir = info.dir; // 어느 방향에서 왔는지
        int curCost = info.cost;
        for(int i=0;i<4;i++){
            int nx = info.x + dx[i];
            int ny = info.y + dy[i];
            if(nx < 0 || nx >= sz || ny < 0 || ny >= sz) continue;
            if(board[nx][ny]) continue;
            int addCost = (direc[i] == direc[prevDir]) ? 100 : 600;
            int nextCost = curCost + addCost;
            if(costTable[nx][ny][i] < nextCost) continue;
            q.push(Info(nx,ny,i,nextCost));
            costTable[nx][ny][i] = nextCost;
        }
    }
    
    int answer = INT_MAX;
    for(int i=0;i<4;i++){
        answer = min(costTable[sz-1][sz-1][i],answer);
    }
    return answer;
}