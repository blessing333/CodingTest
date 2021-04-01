#include<bits/stdc++.h>
using namespace std;
int board[9][9];
int blankCount;
vector<int> v;
bool checkRow(int row,int col,int n){
    //cout <<"checkRow : "<<n<<"\n";
    board[row][col] = n;
    bool checked[10] = {0,};
    for(int i=0;i<9;i++){
        if(board[row][i] == 0) continue;
        if(checked[board[row][i]]){
            board[row][col] = 0;
            return false;
        }
        checked[board[row][i]] = true;
    }
    board[row][col] = 0;
    return true;
}

bool checkCol(int row, int col,int n){
    //cout<<"checkCol : "<<n<<"\n";
    board[row][col] = n;
    bool checked[10] = {0,};
    for(int i=0;i<9;i++){
        if(board[i][col] == 0) continue;
        if(checked[board[i][col]]){
            //cout << "duplicated : " <<board[i][col]<<"\n";
            board[row][col] = 0;
            return false;
        }
        checked[board[i][col]] = true;
    }
    board[row][col] = 0;
    return true;
}

bool checkSquare(int row,int col,int n){
    //cout <<"checkSquare : "<<n<<"\n";
    board[row][col] = n;
    int r = row / 3 *3;
    int c = col / 3 *3;
    bool checked[10] = {0,};
    
    for(int i=r;i<r+3;i++){
        for(int j=c;j<c+3;j++){
            if(board[i][j] == 0) continue;
            if(checked[board[i][j]]){
      //          cout << "duplicated : " <<board[i][col]<<"\n";
                board[row][col] = 0;
                return false;
        }
        checked[board[i][j]] = true;   
        }
    }
    board[row][col] = 0;
    return true;
}

bool func(int level){
    if(level == blankCount){
        return true;
    }
    int pos = v[level];
    //cout <<"pos : " <<pos<<"\n";
    int row = pos / 9;
    int col= pos % 9;
    bool ret= false;
    for(int i=1;i<=9;i++){
        if(!checkRow(row,col,i)) continue;
        if(!checkCol(row,col,i)) continue;
        if(!checkSquare(row,col,i)) continue;
        board[row][col] = i;
        ret = func(level+1);
        if(ret) return true;
        board[row][col] = 0;
    }
    return ret;
}
int main(){
    int pos=0;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin >> board[i][j];
            if(board[i][j] == 0)
                v.push_back(pos);
            pos++;
        }
    }
    blankCount = v.size();
    
    func(0);

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout << board[i][j] <<" ";
        }
        cout << "\n";
    }
}