#include <bits/stdc++.h>
using namespace std;
int board[101][101];
int rotation(int x1,int y1,int x2,int y2){
    priority_queue<int,vector<int>,greater<int>> pq;
    int r = x2-x1+1;
    int c = y2-y1+1;
    int cnt = min(r,c)/2;
    int idx = 0;
    int tmp,tmp2;
    while(idx < 1){ // 내부까지 회전해야 한다면 1을 cnt로 변경
        tmp = board[x1+idx][y1+idx];
        pq.push(tmp);
        for(int i=y1+1+idx; i<=y2-idx;i++){
            tmp2 = board[x1+idx][i];
            board[x1+idx][i]=tmp;
            tmp=tmp2;
            pq.push(tmp);
        }
        for(int i=x1+idx+1; i<=x2-idx;i++){
            tmp2=board[i][y2-idx];
            board[i][y2-idx] = tmp;
            tmp=tmp2;
            pq.push(tmp);
        }
        
        for(int i=y2-1-idx; i>=y1+idx;i--){
            tmp2 = board[x2-idx][i];
            board[x2-idx][i]=tmp;
            tmp=tmp2;
            pq.push(tmp);
        }
        
        for(int i=x2-1-idx; i>=x1+idx;i--){
            tmp2 = board[i][y1+idx];
            board[i][y1+idx]=tmp;
            tmp=tmp2;
            pq.push(tmp);
        }
        idx++;
    }
    return pq.top();
}
vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int value = 1;
    for(int i=1;i<=rows;i++){
        for(int j=1;j<=columns;j++){
            board[i][j]=value++;
        }
    }
    
    int result;
    for(auto it : queries){
        result = rotation(it[0],it[1],it[2],it[3]);
        answer.push_back(result);
    }
    
    return answer;
}