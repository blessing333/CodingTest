#include<bits/stdc++.h>
using namespace std;
int n;
char board[64][64];
string answer;

bool checkCondition(int x, int y,int sz){
    char value = board[x][y];
    for(int i=x; i<x+sz; i++){
        for(int j=y; j<y+sz; j++){
            if(board[i][j] != value) return false;
        }
    }
    return true;
}

void func(int r,int c,int size){
    if(checkCondition(r,c,size)){
        answer.push_back(board[r][c]);
        return;
    }

    else{
        int newSize = size/2;
        answer.push_back('(');
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                func(r+i*newSize,c+j*newSize,newSize);
            }
        }
        answer.push_back(')');
    }
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> board[i][j];
        }
    }
    func(0,0,n);
    cout << answer;
}