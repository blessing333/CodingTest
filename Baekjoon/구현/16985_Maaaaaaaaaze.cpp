#include<bits/stdc++.h>
using namespace std;
vector<int> rotateCount;
vector<int> boardOrder({0,1,2,3,4});
int answer = INT_MAX;
bool board[5][5][5][4];
int visited[5][5][5];
int curBoard[5][5][5];
int dx[] = {1,0,-1,0,0,0};
int dy[] = {0,1,0,-1,0,0};
int dz[] = {0,0,0,0,1,-1};
struct Pos{
    int z;
    int x;
    int y;
    Pos(int a,int b, int c){
        z = a; x=b; y=c;
    }
};

void rotation(){
    for(int i=0;i<5;i++){
        for(int rot = 1; rot <4; rot++){
            for(int j=0;j<5;j++){
                for(int k=0;k<5;k++){
                    board[i][j][k][rot] = board[i][4-k][j][rot-1];
                }
            }
        }
    }
}

int bfs(){
    int result = INT_MAX;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            for(int k=0;k<5;k++){
                visited[i][j][k] = -1;
            }
        }
    }
    queue<Pos> q;
    visited[0][0][0] = 0;
    q.push(Pos(0,0,0));
    while(!q.empty()){
        Pos cur = q.front(); q.pop();
        for(int i=0;i<6;i++){
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            int nz = cur.z + dz[i];
            if(visited[nz][nx][ny] > answer) return answer;
            if(nx >= 5 || nx < 0 || ny >= 5 || ny < 0 || nz >=5 || nz < 0) continue;
            if(!curBoard[nz][nx][ny] || visited[nz][nx][ny] > -1) continue;
            if(nx == 4 && ny ==4 && nz ==4){
                return visited[cur.z][cur.x][cur.y] + 1;
            }
            q.push(Pos(nz,nx,ny));
            visited[nz][nx][ny] = visited[cur.z][cur.x][cur.y] + 1;
        }
    }
    return result;
}

void solution(){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            for(int k=0;k<5;k++){
                curBoard[i][j][k] = board[boardOrder[i]][j][k][rotateCount[i]];
            }
        }
    }
    if(!curBoard[0][0][0] || !curBoard[4][4][4]) return;
    int candi = bfs();
    if(candi != INT_MAX) answer = min(candi,answer);
}

void permu(){
    if(rotateCount.size() == 5){
        solution();
        return;
    }
    else{
        for(int i=0;i<4;i++){
            rotateCount.push_back(i);
            permu();
            rotateCount.pop_back();
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            for(int k=0;k<5;k++){
                cin >> board[i][j][k][0];
            }
        }
    }

    rotation();
    
    do{
        permu();
    } while(next_permutation(boardOrder.begin(),boardOrder.end()));
    answer = answer != INT_MAX ? answer : -1;
    cout << answer;
}