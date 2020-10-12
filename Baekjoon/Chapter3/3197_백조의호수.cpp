#include<bits/stdc++.h>
using namespace std;
int r,c,result=-1,dx[]={1,0,-1,0},dy[]={0,1,0,-1},end_x,end_y;
char board[1500][1500];
bool visit[1500][1500],visit2[1500][1500];
queue<pair<int,int>> baekjo,ice;
/*
    백조끼리 만나면 false 반환, 아니면 true 반환
*/
bool move(){
    queue<pair<int,int>> tmp;
    while(!baekjo.empty()){
        pair<int,int> cur = baekjo.front();baekjo.pop();
        if(cur.first==end_x && cur.second == end_y) return false;
                
        for(int i=0;i<4;i++){
            int nx=cur.first+dx[i];
            int ny=cur.second+dy[i];
            if(nx>=r || nx<0 || ny>=c || ny<0) continue;
            if(!visit[nx][ny] && board[nx][ny]=='.'){
                baekjo.push({nx,ny});
                visit[nx][ny]=true;
            }
            else if(!visit[nx][ny] && board[nx][ny]=='X'){
                tmp.push({nx,ny}); // 다음날 탐색 시작 위치
                visit[nx][ny]=true;
            }
        }
    }
    baekjo=tmp;
    return true;
}

/*
    물과 맞닿은 얼음을 찾아 녹이는 함수
    최초 실행 시점에 ice에는 물의 좌표가 들어있고
    두 번째 실행 이후부터 녹은 얼음의 좌표가 들어있음
*/
void melt(){
    queue<pair<int,int>> tmp;
    while(!ice.empty()){
        pair<int,int> cur=ice.front();ice.pop();
        for(int i=0;i<4;i++){
            int nx=cur.first+dx[i];
            int ny=cur.second+dy[i];
            if(nx>=r || nx<0 || ny>=c || ny<0) continue;
            if(!visit2[nx][ny] && board[nx][ny]=='X'){
                tmp.push({nx,ny});
                visit2[nx][ny]=true;
                board[nx][ny]='.';
            }
        }
    }
    ice=tmp;
}

int main(){
    int cnt=0;
    cin >> r >> c;
    for(int i=0; i < r;i++){
        for(int j=0; j<c; j++){
            cin >> board[i][j];
            if(board[i][j]=='L'){
                if(cnt==0){
                    baekjo.push({i,j});cnt++;
                    visit[i][j]=true;
                }
                else{
                    end_x=i;end_y=j;
                }
                board[i][j]='.';
            }
            if(board[i][j]=='.'){
                ice.push({i,j});
                visit2[i][j]=true;
            }
        }
    }
    bool flag=true;
    while(flag){
        result++;
        flag=move();
        melt();
    }
    cout << result;
}