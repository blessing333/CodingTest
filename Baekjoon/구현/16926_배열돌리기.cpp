#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int board[300][300];

void rotation(){
    int tmp[300][300];
    int d = min(n,m) / 2;
    int idx = 0;
    int r =n-1,c=m-1;
    while(idx < d){
        for(int i = c-1-idx; i>= idx; i--){
            tmp[idx][i] = board[idx][i+1];
        }
        for(int i=1+idx;i<=r-idx;i++){
            tmp[i][idx] = board[i-1][idx];
        }
        for(int i=idx+1; i<= c-idx ; i++){
            tmp[r-idx][i] = board[r-idx][i-1];
        }
        for(int i = r-idx-1; i>= idx; i--){
            tmp[i][c-idx] = board[i+1][c-idx];
        }
        idx++;
    }
    copy(&tmp[0][0],&tmp[0][0]+300*300,&board[0][0]);
}

int main(){
    cin >> n >> m >> k;   
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
        }
    }

    while(k-- > 0){        
        rotation();
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}