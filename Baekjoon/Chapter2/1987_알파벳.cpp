#include<bits/stdc++.h>
using namespace std;
int r,c,result;
bool flag=false;
char board[20][20];
bool visit[20][20];
int arr[26];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
stack<char> s;
void dfs(int x,int y, int cnt){
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=r||nx<0||ny>=c||ny<0) continue;
        
        if(arr[board[nx][ny]-'A']){
            continue;
        }
        arr[board[nx][ny]-'A']=1;
        result=max(result,cnt);
        dfs(nx,ny,cnt+1);

    }
}
int main(){
    cin >> r >> c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> board[i][j];
        }
    }
    arr[board[0][0]-'A']=1;
    dfs(0,0,1);
    cout<<result;
    
}