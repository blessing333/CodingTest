//테스트 케이스로 불이 없을 떄, 불이 여러개일 떄 고려, 불이 벽을 넘지 않도록 작성
#include<bits/stdc++.h>
using namespace std;
int MMM = 987654321;
char board[1000][1000];
int firemap[1000][1000];
int visit[1000][1000];
int dist[1000][1000];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
bool flag=false;
int r,c,cnt;
queue<pair<int,int> > fire,q;
int main(){
    fill(&firemap[0][0],&firemap[0][0]+1000000,MMM);
    fill(&dist[0][0],&dist[0][0]+1000000,-1);

    cin >> r >> c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> board[i][j];
            if(board[i][j]=='F'){
                firemap[i][j]=0;
                visit[i][j]=1;
                fire.push({i,j});
            }
            else if(board[i][j]=='J'){
                dist[i][j]=0;
                q.push({i,j});
            }
        }
    }

    while(!fire.empty()){
        pair<int,int> cur=fire.front();fire.pop(); 
        for(int i=0;i<4;i++){
            int nx=cur.first+dx[i];
            int ny=cur.second+dy[i];
            if(nx>=r||nx<0||ny>=c||ny<0) continue;
            if(!visit[nx][ny]&&board[nx][ny]=='.'){
            visit[nx][ny]=1;
            firemap[nx][ny]=firemap[cur.first][cur.second]+1;
            fire.push({nx,ny});
            }
        }
    }

    while(!q.empty()){
        pair<int,int> cur=q.front();q.pop();
        if(cur.first==0 || cur.first==r-1 ||cur.second ==0 ||cur.second ==c-1){
            cnt=dist[cur.first][cur.second]+1;
            flag=true;
            break;
        }
        for(int i=0;i<4;i++){
            int nx=cur.first+dx[i];
            int ny=cur.second+dy[i];
            if(nx>=r||nx<0||ny>=c||ny<0) continue;
            if(board[nx][ny]=='.' && dist[nx][ny]<0 && dist[cur.first][cur.second]+1<firemap[nx][ny]){
            dist[nx][ny]=dist[cur.first][cur.second]+1;
            q.push({nx,ny});
            }
        }
    }


    if(flag)
        cout << cnt;
    
    else
        cout<<"IMPOSSIBLE";

}