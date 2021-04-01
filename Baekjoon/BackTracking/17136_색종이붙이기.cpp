#include<bits/stdc++.h>
using namespace std;
int board[10][10];
int paper[5]={5,5,5,5,5};
bool checkCanAttach(int s,int pos){
    int row = pos / 10;
    int col = pos % 10;
    if(row+s > 9 || col + s > 9) return false;
    for(int i=row; i<=row+s;i++){
        for(int j=col; j<=col+s; j++){            
            if(board[i][j]==0){                
                return false;
            }
        }
    }
    return true;
}

void attach(int s,int pos){
    int row = pos / 10;
    int col = pos % 10;
    for(int i=row; i<=row+s;i++){
        for(int j=col;j<=col+s;j++){
            board[i][j] = 0;
        }
    }
}


int func(int cnt, int pos){ 
    if(cnt >= 25 || pos >= 10 * 10){
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                if(board[i][j]) return INT_MAX; 
            }
        }
        return cnt;
    }
    
    int row = pos/10;
    int col = pos%10;
    int ret = INT_MAX;
    
    if(board[row][col]){
        for(int i=4;i>=0;i--){
            if(checkCanAttach(i,pos) && paper[i] != 0){ 
                int tmp[10][10];
                copy(&board[0][0],&board[0][0] + 100,&tmp[0][0]);
                attach(i,pos);
                paper[i]--;
                ret=min(func(cnt+1,pos+1),ret);
                paper[i]++;
                copy(&tmp[0][0],&tmp[0][0] + 100,&board[0][0]);
            }
        }
    }
    else ret=min(ret,func(cnt,pos+1));
    return ret;
}

int main(){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cin >> board[i][j];
        }
    }
    int answer = func(0,0);
    if(answer == INT_MAX) cout << -1;
    else cout << answer;
}