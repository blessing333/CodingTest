#include<bits/stdc++.h>
using namespace std;
int board[9][9];
deque<pair<int,int>> v;
bool done = false;
bool checkRow(int num,int x){
    for(int i=0;i<9;i++){
        if(num == board[x][i]) return false;
    }
    return true;
}

bool checkCol(int num,int col){
    for(int i=0;i<9;i++){
        if(num == board[i][col]) return false;
    }
    return true;
}
bool checkSquare(int num,int row,int col){
    row = row / 3 * 3;
    col = col / 3 * 3;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(num == board[row+i][col+j]) return false;
        }
    }
    return true;
}

void func(deque<pair<int,int>> list){
    if(done) return;
    if(list.size() == 0){
        done = true;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout << board[i][j];
            }
            cout <<"\n";
        }
        return;
    }
    else{
        pair<int,int> cur = list.front();list.pop_front();
        int x = cur.first;
        int y = cur.second;
        for(int i=1;i<10;i++){
            if(checkRow(i,x) && checkCol(i,y) && checkSquare(i,x,y)){ //숫자가 들어갈수잇으면
                int tmp = board[x][y];
                board[x][y] = i;
                func(list);
                board[x][y] = tmp;
            }
        }
    }

}
int main(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            scanf("%1d",&board[i][j]);
            if(board[i][j] == 0){
                v.push_back({i,j});
            }
        }
    }
    
    func(v);
}