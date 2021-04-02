#include<bits/stdc++.h>
using namespace std;
int n;
int idx;
int board[10][10];
int answer;

map<int,int> plusCross;
map<int,int> minusCross;
bool checkCondition(int row,int col){
    //1. 하향 대각선에 비숍이 있는지 체크
    int pos = row-col;
    if(minusCross[pos] > 0) return false;
    //2. 상향 대각선에 비숍이 있는지 체크
    pos = row+col;
    if(plusCross[pos] > 0) return false;
    return true;
}

void func(int pos,int cnt,int color){ //pos자리에 비숍이 놓일 수 있는지 확인한다.
    if(pos >= n*n){
        answer = max(answer,cnt);
        return;
    }
    int row = pos / n;
    int col = pos % n;
    int nextRow=(pos+2) / n;
    int nxt=0;
    if(nextRow > row && n %2 == 0 && color==0){
        if(row%2==0) nxt=1;
        else nxt=-1;
    }
    if(nextRow > row && n %2 == 0 && color==1){
        if(row%2!=0) nxt=1;
        else nxt=-1;
    }
    if(checkCondition(row,col) && board[row][col]){ //비숍을 둘 수 있으면    
        minusCross[row-col]++;
        plusCross[row+col]++;
        func(pos+2+nxt,cnt+1,color); //비숍을 두거나
        minusCross[row-col]--;
        plusCross[row+col]--;
    }
    func(pos+2+nxt,cnt,color); //두지 않거나
}
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> board[i][j];
        }
    }
    func(0,0,0);
    int answer1 = answer;
    
    answer=0;
    plusCross.clear();
    minusCross.clear();
    
    func(1,0,1);
    cout << answer1+answer;
    
}