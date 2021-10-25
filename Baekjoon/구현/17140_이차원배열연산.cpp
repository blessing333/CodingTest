#include<bits/stdc++.h>
using namespace std;
int r,c,k;
struct Info{
    int val;
    int cnt;
    bool operator< (const Info &a ) const{
        if(cnt == a.cnt) return val < a.val;
        else return cnt < a.cnt;
    }
    Info(int a,int b){
        val = a; cnt = b;
    }
};
vector<vector<int>> board(3,vector<int>(3));

vector<vector<int>> R(){
    int row = board.size();
    int col = board[0].size();
    vector<vector<int>> ret;
    int sz = -1;
    for(int i=0;i<row;i++){
        if(i == 100) break;
        vector<Info> oneRow;
        unordered_map<int,int> frequency;
        for(int j=0;j<col;j++){
            if(j== 100) break;
            if(board[i][j] != 0)
                frequency[board[i][j]]++;
        }

        for(auto it : frequency){
            oneRow.push_back(Info(it.first,it.second));
        }

        sort(oneRow.begin(),oneRow.end());
        
        vector<int> v;
        for(auto it : oneRow){
            v.push_back(it.val);
            v.push_back(it.cnt);
        }

        sz = max((int)v.size(),sz);
        ret.push_back(v);    
    }

    for(auto &it : ret){ // 0 채우기
            int iter = sz - it.size();
            for(int i=0;i<iter;i++) it.push_back(0);
    }
    return ret;
}

vector<vector<int>> C(){
    int row = board.size();
    int col = board[0].size();
    vector<vector<int>> ret;
    int sz = -1;

    for(int i=0;i<col;i++){
        vector<Info> oneRow;
        unordered_map<int,int> frequency;
        for(int j=0;j<row;j++){
            if(board[j][i] != 0)
                frequency[board[j][i]]++;
        }
        
        for(auto it : frequency){
            oneRow.push_back(Info(it.first,it.second));
        }

        sort(oneRow.begin(),oneRow.end());
        
        vector<int> v;
        for(auto it : oneRow){
            v.push_back(it.val);
            v.push_back(it.cnt);
        }

        sz = max((int)v.size(),sz);
        ret.push_back(v);    
    }

    for(auto &it : ret){ // 0 채우기
        int iter = sz - it.size();
        for(int i=0;i<iter;i++) it.push_back(0);
    }
    row = ret.size();
    vector<vector<int>> tmp(sz,vector<int>(row,0));
    for(int i=0;i<row;i++){
        if(i == 100) break;
        for(int j=0;j<ret[0].size();j++){
            if(j == 100) break;
            tmp[j][i] = ret[i][j];
        }
    }
    return tmp;
}

int main(){
    cin >> r >> c >> k;
    r--; c--;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin >> board[i][j];
        }
    }
    
    int limit = 101;
    int cnt = 0;
    int answer = -1;
    
    while(limit--){
        int curR = board.size();
        int curY = board[0].size();
        if(board.size() > r &&  board[0].size()> c && board[r][c] == k) {
            answer = cnt;
            break;
        }
        board = curR >= curY ? R() : C();
        cnt++;
    }
    cout <<  answer;
}