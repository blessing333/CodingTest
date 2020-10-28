#include<bits/stdc++.h>
using namespace std;
int node,edge;
int board[20][20];
int main(){
    cin >> node>> edge;
    for(int i=0;i<edge;i++){
        int r,c,w;
        cin >> r >> c >> w;
        board[r-1][c-1]=w;
    }

    for(int i=0;i<node;i++){
        for(int j=0;j<node;j++){
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}