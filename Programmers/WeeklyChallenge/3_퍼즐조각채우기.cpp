#include <bits/stdc++.h>

using namespace std;
bool visited[55][55];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
bool shapeCheck[2505];

bool checkMatching(vector<pair<int,int>> blank, vector<pair<int,int>> shape){
    if((int)blank.size() != shape.size()) return false;
    sort(blank.begin(),blank.end());
    sort(shape.begin(),shape.end());
    for(int i=0;i<blank.size();i++){
        if(shape[i].first != blank[i].first || shape[i].second != blank[i].second) return false;
    }
    return true;
}

void moveEdge(vector<pair<int,int>> &target){
    int row = 100; int col = 100;
    for(auto it : target){
        row = min(row,it.first);
        col = min(col,it.second);
    }
    
    for(auto &it : target){
        it.first -= row;
        it.second -= col;
    }
}

void rotate(vector<pair<int,int>> &shape){
    int sz = 0;
    for(auto it : shape){
        if(it.first > sz || it.second > sz) sz = max(it.first,it.second);
    }
    sz++;
    for(auto &it : shape){
        int rTmp = it.first;
        it.first = it.second;
        it.second = sz-1-rTmp;
    }
    moveEdge(shape);
}

vector<pair<int,int>> extractShape(int x,int y,int target,vector<vector<int>> board){
    int sz = (int)board.size();
    vector<pair<int,int>> result;
    queue<pair<int,int>> q;
    visited[x][y] = true;
    q.push({x,y});
    result.push_back({x,y});
    while(!q.empty()){
        pair<int,int> cur = q.front(); q.pop();
        for(int i=0;i<4;i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx >= sz || nx < 0 || ny >= sz ||ny < 0) continue;
            if(board[nx][ny] != target || visited[nx][ny]) continue;
            visited[nx][ny] = true;
            q.push({nx,ny});
            result.push_back({nx,ny});
        }
    }
    moveEdge(result);
    return result;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    int sz = (int)game_board.size();
    vector<vector<pair<int,int>>> blank;
    vector<vector<pair<int,int>>> shape;
   
    
    for(int i=0;i<sz;i++){
        for(int j=0;j<sz;j++){
            if(!visited[i][j] && game_board[i][j] == 0){
                blank.push_back(extractShape(i,j,0,game_board));
            }
        }
    }
    
    
    fill(&visited[0][0],&visited[0][0] + 55*55 , 0);
    
    for(int i=0;i<sz;i++){
        for(int j=0;j<sz;j++){
            if(!visited[i][j] && table[i][j] == 1){
                shape.push_back(extractShape(i,j,1,table));
            }
        }
    }
    int blankSize = (int)blank.size();
    int shapeSize = (int)shape.size();
    if(blankSize <= 0 || shapeSize <= 0 ) return 0;
    
    for(auto it : blank){
        bool isMatching = false;
        for(int i=0;i<shapeSize;i++){
            if(shapeCheck[i]) continue;
            for(int j=0; j<5;j++){
                isMatching = checkMatching(it,shape[i]);
                if(isMatching){
                    answer+=shape[i].size();
                    shapeCheck[i] = true;
                    break;
                }
                rotate(shape[i]);
            }
            if(isMatching) break;
        }
    }
    return answer;
}