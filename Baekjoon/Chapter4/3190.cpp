#include<bits/stdc++.h>
using namespace std;
int n,k,l,board[101][101],sz=1;
int dx[]={-1,0,1,0},dy[]={0,1,0,-1},dir=1;
deque<pair<int,int>> snake;
queue<pair<int,int>> q;
int main(){
    cin >> n;
    cin >> k;
    for(int i=0;i<k;i++){
        int a,b; cin >> a >> b;
        board[a][b]=2;
    }
    cin >> l;
    for(int i=0;i<l;i++){
        int t,dd;char d;
        cin >> t >> d;
        if(d=='D') dd=1;
        else dd=-1;
        q.push({t,dd});
    }
    int ret=0;
    board[1][1]=1;
    snake.push_back({1,1});
    while(true){
        ret++;
        pair<int,int> direction=q.front();
        pair<int,int> cur=snake.back();
        int nx = cur.first+dx[dir];
        int ny= cur.second+dy[dir];
        if(nx>n || nx<=0 || ny> n || ny<=0 || board[nx][ny]==1) break;
        snake.push_back({nx,ny});
        if(board[nx][ny]==2) sz++;
        board[nx][ny]=1;
        if(snake.size()>sz){
            pair<int,int> tail=snake.front();snake.pop_front();
            board[tail.first][tail.second]=0;
        }

         if(ret==direction.first){
            q.pop();
            dir+=direction.second;
            if(dir==-1) dir=3;
            else if(dir==4) dir=0;
        }
    }
    cout << ret;
}