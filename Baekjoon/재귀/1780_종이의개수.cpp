#include<bits/stdc++.h>
using namespace std;
int N;
int board[2200][2200];
int score[3];

bool checkCondition(int sz,int x, int y){
    int value = board[x][y];
    for(int i=x; i<x+sz; i++){
        for(int j=y; j<y+sz; j++){
            if(board[i][j] != value){
                return false;
            }
        }
    }
    return true;
}

void func(int n,int r,int c){
    if(checkCondition(n,r,c)){
        score[board[r][c]]++;
        return;
    }

    else{
        int sz = n/3;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                func(sz,i*sz+r,j*sz+c);
            }
        }
    }
}

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int a; cin >> a; a++;
            board[i][j] = a;
        }
    }
    func(N,0,0);
    for(int i=0;i<3;i++){
        cout << score[i] <<"\n";
    }
}