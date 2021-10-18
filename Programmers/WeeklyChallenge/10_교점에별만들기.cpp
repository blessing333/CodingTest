#include <bits/stdc++.h>


using namespace std;

vector<string> solution(vector<vector<int>> line) {
    vector<pair<int,int>> pos;
    int sz = line.size();
    int minR=INT_MAX ,minC = INT_MAX;
    int maxR=INT_MIN, maxC = INT_MIN;
    
    for(int i=0;i<sz-1;i++){ //교점 구하기
        vector<int> info = line[i];
        for(int j=i+1;j<sz;j++){
            vector<int> info2 = line[j];
            long long A = info[0];
            long long B = info[1];
            long long E = info[2];
            long long C = info2[0];
            long long D = info2[1];
            long long F = info2[2];
            if((A*D) - (B*C) == 0) continue;
            if(((B*F) - (E*D)) % (A*D - B*C) != 0 || ((E*C) - (A*F)) % (A*D - B*C) != 0) continue;
            int c = ((B*F) - (E*D)) / ((A*D) - (B*C));
            int r = ((E*C) - (A*F)) / ((A*D) - (B*C));
            maxR = max(maxR,r);
            minR = min(minR,r);
            
            maxC = max(maxC,c);
            minC = min(minC,c);
            
            pos.push_back({r,c});
        }
    }

   vector<vector<char>> board(maxR-minR+1,vector<char>(maxC-minC+1,'.'));
    
    for(auto it : pos){
        board[maxR-it.first][it.second-minC] ='*';
    }
    
    vector<string> answer;
    
    
    for(int i=0;i<maxR-minR+1;i++){
        string token;
        for(int j=0;j<maxC-minC+1;j++){
            token.push_back(board[i][j]);
        }
        answer.push_back(token);
    }
    
    return answer;
}