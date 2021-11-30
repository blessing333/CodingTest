#include <bits/stdc++.h>

using namespace std;

struct Info{
    int x;
    int y;
    int dir;
    int cnt;
    Info(int a,int b,int c,int d){
        x =a; y=b; dir =c; cnt = d;
    }
};

int dx[4];
int dy[4];
bool visited[101][101][4];
int N,M;
vector<string> board;
vector<char> answer;
unordered_map<char,vector<pair<int,int>>> ma;
string str;

bool dfs(int x,int y){ //dfs로 제거할 수 있는지 판별
    bool ret = false;
    char key = board[x][y];
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<4;k++){
                visited[i][j][k] = false;
            }
        }
    }
    for(int i=0;i<4;i++)
        visited[x][y][i] = true;
    
    stack<Info> stk;
    stk.push({x,y,0,0});
    while(!stk.empty()){
        Info info = stk.top(); stk.pop();
        for(int i=0;i<4;i++){
            int nx = info.x + dx[i];
            int ny = info.y + dy[i];
            int nc = info.cnt;
            if(i != info.dir) nc++;
            if(nc > 2) continue;
            if(nx >= M || nx <0 || ny >= N || ny < 0) continue;
            if(visited[nx][ny][i]) continue;
            if(board[nx][ny] == '.'){
                visited[nx][ny][i] = true;
                stk.push({nx,ny,i,nc});
            }
            else if(board[nx][ny] == key){
                ret = true;
                visited[nx][ny][i] = true;
                vector<pair<int,int>> candi;
                candi.push_back({nx,ny});
                candi.push_back({x,y});
                ma.insert({key,candi});
                answer.push_back(key);
                while(!stk.empty()){
                    stk.pop();
                }
                break;
            }
        }
    }
    return ret;
}

string solution(int m, int n, vector<string> bod) {
    N=n;
    M=m;
    board = bod;
    dx[0] = -1;
    dx[1] = 0;
    dx[2] = 1;
    dx[3] = 0;
    dy[0] = 0;
    dy[1] = 1;
    dy[2] = 0;
    dy[3] = -1;
    answer.clear();
    ma.clear();
    str ="";
    bool isUpdate = true;
    while(isUpdate){
        bool check[26]={0,};
        isUpdate = false;
        for(int i=0;i<m;i++){
            for(int j= 0;j<n;j++){
                if(isalpha(board[i][j])){
                    if(check[board[i][j] - 'A']) continue;
                    check[board[i][j]-'A'] = true;
                    if(dfs(i,j))
                        isUpdate = true;
                }
            }
        }
        if(answer.size() > 0){
            sort(answer.begin(),answer.end());
            char key = answer[0];
            str.push_back(key);
            vector<pair<int,int>> pos = ma[key];
            for(auto it : pos){
                board[it.first][it.second] = '.';
            }
            answer.clear();
            ma.clear();
        }
        
    }
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(isalpha(board[i][j])){
                return "IMPOSSIBLE";
            }
        }
    }
    return str;
}