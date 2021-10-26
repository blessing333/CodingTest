#include<bits/stdc++.h>
using namespace std;
int n, m ,k;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
//int sharkBoard[21][21];

struct Shark{
    int x;
    int y;
    int dir;
    int prefer[4][4];
    Shark(int a,int b){
        x = a; y = b;
    }
    Shark(){
        
    }
};

struct Next{
    int nx;
    int ny;
    int nd;
    Next(int a,int b,int c){
        nx = a; ny = b; nd = c;
    }
};

map<int,Shark> sharkMap;
int board[21][21];
vector<vector<pair<int,int>>> smell(21);


void marking(){
    for(auto it : sharkMap){
        int x = it.second.x;
        int y = it.second.y;    
        smell[x][y].first = it.first;
        smell[x][y].second = k;    
    }
}

void move(){
    vector<int> shouldDelete;
    int tmp[21][21];
    fill(&tmp[0][0],&tmp[0][0] + 21 *21 , 0);
    
    for(auto &it : sharkMap){ //1. 움직일 방향 탐색
        Shark *shark = &it.second;
        Next next = Next(-1,-1,-1);
        vector<Next> candi;
        bool isFind = false;
        for(int i=0;i<4;i++){
            int nd = shark->prefer[shark->dir][i];
            int nx = shark -> x + dx[nd];
            int ny = shark -> y + dy[nd];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            
            if(smell[nx][ny].first == 0){ //냄새가 없는 경우
                next = (Next(nx,ny,nd));
                isFind = true;
                break;
            }
            else if(smell[nx][ny].first == it.first){ //자기 냄새일 경우
                candi.push_back(Next(nx,ny,nd)); 
            }

        }
        
        if(!isFind) next = candi[0];

        if(tmp[next.nx][next.ny]) shouldDelete.push_back(it.first); //이미 다른 상어가 있으면 잡아먹힘
        else{ // 상어 정보 갱신
            tmp[next.nx][next.ny] = it.first;
            //smellTmp[next.nx][next.ny] = it.first;
            shark-> x = next.nx;
            shark-> y = next.ny;
            shark -> dir = next.nd;
        }
    }

    for(auto it : shouldDelete) sharkMap.erase(it);
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> board[i][j];
            if(board[i][j]){
                int id = board[i][j];
                sharkMap.insert({id,Shark(i,j)});
            }
            smell[i].push_back({0,0});
        }
    }
    for(int i=1;i<=m;i++){
        int d; cin >> d;
        sharkMap[i].dir = d-1;
    }
    
    for(int i=1;i<=m;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<4;k++){
                int d; cin >> d;
                sharkMap[i].prefer[j][k] = d-1;
            }
            
        }
    }    
    int limit = 1001;
    int cnt = 0;
    marking();
    while(limit--){
        move(); // 이동
        cnt++;
        if(sharkMap.size() == 1) break;
        for(int i=0;i<n;i++){ //냄새 제거
            for(int j=0;j<n;j++){
                if(smell[i][j].first == 0) continue;
                
                if(smell[i][j].second >= 1)
                    smell[i][j].second--;

                if(smell[i][j].second == 0)
                    smell[i][j].first = 0;
            }
        }
        marking(); // 냄새남기기
    }
    if(cnt >= 1001) cout << -1;
    else cout << cnt;
}