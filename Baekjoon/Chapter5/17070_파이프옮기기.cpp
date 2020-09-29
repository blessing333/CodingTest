#include<bits/stdc++.h>
using namespace std;
int n,board[16][16],cnt;
int dx[]={0,1,1},dy[]={1,0,1};

void dfs(int x,int y,int z){
    if(x==n-1 && y==n-1){
        cnt++;
        return;
    }

    for(int i=0;i<3;i++){
        if (i + z==1)continue;
		int nx = x + dx[i], ny = y + dy[i];
		if (nx >= n || ny >= n || board[nx][ny])continue;
		if (i == 2 && (board[x + 1][y] || board[x][y + 1]))continue;
        dfs(nx,ny,i);
    }
}
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> board[i][j];
        }
    }
    dfs(0,1,0);
    cout << cnt;
}