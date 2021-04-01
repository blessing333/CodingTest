#include<bits/stdc++.h>
using namespace std;
int n,m,h;
int board[30][10];

bool check(){
    for(int i=0;i<n;i++){
        int row=0, col=i;
        do{
            if(board[row][col] == 1){
                ++col;
            }
            else if(board[row][col] == 2){
                --col;
            }
            ++row;
        } while (row != h);
        if(col != i) return false;
    }
    return true;
}

int func(int pos, int cnt){
    int ret = INT_MAX;
    int row = pos / n;
    int col = pos % n;
    
    if(cnt == 3 || pos >= n*h){
        if(check()){
            return cnt;
        }
        return INT_MAX;
        
    }

    if(col != n-1 && board[row][col] == 0 && board[row][col+1] ==0){
        board[row][col] = 1;
        board[row][col+1] = 2;
        ret = min(ret,func(pos+2,cnt+1));
        board[row][col] = 0;
        board[row][col+1] = 0;
    }
    ret=min(ret,func(pos+1,cnt));
    return ret;
}
int main(){
    int answer;
    cin >> n >> m >> h;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        board[a-1][b-1]=1;
        board[a-1][b]=2;
    }
    answer = func(0,0);
    if(answer == INT_MAX) cout << -1;
    else cout << answer;
}