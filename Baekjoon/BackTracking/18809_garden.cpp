#include<bits/stdc++.h>
using namespace std;
int n,m,g,r;
int board[50][50];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
vector<pair<int,int>> candi;
vector<pair<int,int>> redStart;
vector<pair<int,int>> greenStart;
vector<int> v;
bool visited[50][50];
int redTimeMap[50][50];
int greenTimeMap[50][50];
int answer = 0;
int logic(){
    int ret = 0;
    pair<int,int> state[50][50]; // 0 empty, 1 red, 2 grean, 3 flower
    queue<pair<int,int>> q;
    for(auto it : redStart){
        q.push(it);
        state[it.first][it.second]= {0,1};
        
    }

    for(auto it : greenStart){
        q.push(it);
        state[it.first][it.second] = {0,2};
    }

    while(!q.empty()){
        pair<int,int> cur = q.front();q.pop();
        int curTime = state[cur.first][cur.second].first;
        int curColor = state[cur.first][cur.second].second;
        if(state[cur.first][cur.second].second == 3 ) continue;

        for(int i=0;i<4;i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx >= n || nx < 0 || ny >= m || ny < 0) continue;
            if(board[nx][ny] == 0) continue;
            
            if(state[nx][ny].second == 0){ // 비어있으면
                state[nx][ny] = {curTime +1,curColor};
                q.push({nx,ny});
            }

            else if(state[nx][ny].second == 1){ // 빨간 배양액이면
                if(curColor == 2 && curTime + 1 == state[nx][ny].first){
                    ret++; // 꽃이 피었다.
                    state[nx][ny].second = 3;
                }
            }

            else if(state[nx][ny].second == 2){ // 초록 배양액이면
                if(curColor == 1 && curTime+1 == state[nx][ny].first){
                    ret++;
                    state[nx][ny].second = 3;
                }
            }
        }
    }
    return ret;
}

void func(int red,int green,int idx){
    if(idx == r+g){
        answer = max(logic(),answer);
        return;
    }
    else{
        int nx = candi[v[idx]].first;
        int ny = candi[v[idx]].second;
        if(red != 0){
            redStart.push_back({nx,ny});
            func(red-1,green,idx+1);
            redStart.pop_back();
        }
        if(green != 0){
            greenStart.push_back({nx,ny});
            func(red,green-1,idx+1);
            greenStart.pop_back();
        }
    }
    
}

void combi(int n){
    if(v.size()== r+g){
        func(r,g,0);
        return;
    }
    else{
        for(int i=n+1;i<candi.size();i++){
            v.push_back(i);
            combi(i);
            v.pop_back();
        }
    }
    
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> g >> r;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
            if(board[i][j] == 2){
                candi.push_back({i,j});
            }
        }
    }
    combi(-1);
    cout << answer;
}