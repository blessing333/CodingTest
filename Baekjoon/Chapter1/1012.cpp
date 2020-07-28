#include<bits/stdc++.h>
using namespace std;

int T,M,N,K;
int X,Y,result;
int board[55][55];
int visit[55][55];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
queue<pair<int,int>> q;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin >> T;
    for(int i=0;i<T;i++){
        fill(&board[0][0],&board[0][0]+55*55,0);
        fill(&visit[0][0],&visit[0][0]+55*55,0);
        cin >> M >> N >> K;
        for(int i=0;i<K;i++){
        cin >> X >> Y;
        board[X][Y]=1;
        }
        for(int i=0;i<M;i++){
            for(int j=0;j<M;j++){
                if(visit[i][j]==1 || board[i][j] ==0)
                    continue;
                    result++;
                q.push({i,j});
                visit[i][j]=1;
                while(!q.empty()){
                    pair<int,int> cur=q.front();
                    q.pop();
                    for(int dir=0;dir<4;dir++){
                        int nx=cur.first+dx[dir];
                        int ny=cur.second+dy[dir];
                        if(nx<0||nx>=M||ny<0||ny>=N)continue;
                        if(visit[nx][ny]==1 || board[nx][ny]==0)continue;
                        visit[nx][ny]=1;
                        q.push({nx,ny});
                    }
                }
            }
        }
    printf("%d\n",result);
    result=0;
    }
}