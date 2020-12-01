#include<bits/stdc++.h>
using namespace std;
int r,c,ret;
char board[20][20];
bool check[26];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
void dfs(int x, int y,int cnt){
    ret=max(cnt,ret);
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];

        if(nx >= r || nx<0 || ny>=c || ny<0) continue;
        int k=(int)board[nx][ny]-'A';
        if(check[k]) continue;
        check[k]=true;
        dfs(nx,ny,cnt+1);
        check[k]=false;
    }
    
}
int main(){
    scanf("%d %d",&r,&c);
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf(" %1c",&board[i][j]);
        }
    }
    check[(int)board[0][0]-'A']=true;
    cout << board[0][0]-'A';
    dfs(0,0,1);
    printf("%d",ret);

}