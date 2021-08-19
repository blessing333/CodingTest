#include<bits/stdc++.h>

using namespace std;
bool checkPartition(pair<int,int> pos1,pair<int,int> pos2,vector<string> board){
    bool result = false;
    int r1 = pos1.first;
    int r2 = pos2.first;
    int c1 = pos1.second;
    int c2 = pos2.second;
    
    if(r1 == r2 && c1 > c2){
        if(board[r1][c1-1] == 'X') result = true;
    }
    else if(r1 == r2 && c1 < c2){
        if(board[r1][c1+1] == 'X') result= true;
    }
    else if(c1 == c2 && r1 > r2){
        if(board[r1-1][c1] == 'X') result = true;
    }
    else if(c1 == c2 && r1 < r2){
        if(board[r1+1][c1] == 'X') result = true;
    }
    
    else if(c1 < c2 && r1 < r2){
        if(board[r1+1][c1] == 'X' && board[r1][c1+1] == 'X') result = true;
    }
    else if(c1 > c2 && r1 > r2){
        if(board[r1-1][c1] == 'X' && board[r1][c1-1] == 'X') result = true;
    }
    else if(c1 < c2 && r1 > r2){
        if(board[r1-1][c1] == 'X' && board[r1][c1+1] == 'X') result = true;
    }
    else if(c1 > c2 && r1 < r2){
        if(board[r1+1][c1] == 'X' && board[r1][c1-1] == 'X') result = true;
    }
    return result;
}

int getDist(pair<int,int> pos1,pair<int,int> pos2){
    int r1 = pos1.first;
    int r2 = pos2.first;
    int c1 = pos1.second;
    int c2 = pos2.second;
    return abs(r2-r1) + abs(c2-c1);
}

bool solution(vector<string> board){
    bool result = true;
    vector<pair<int,int>> candi;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(board[i][j] == 'P')
                candi.push_back({i,j});
        }
    }
    int sz = candi.size();
    for(int i=0;i<sz-1;i++){
        for(int j=i+1;j<sz;j++){
            int dist = getDist(candi[i],candi[j]);
            if(dist == 1) {
                return false;
            }
            else if(dist == 2){
                bool check = checkPartition(candi[i],candi[j],board);
                if(!check){
                    return false;
                }
            }
            
        }
    }
    return result;
        
}
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(auto board : places){
        answer.push_back(solution(board));
    }
    return answer;
}