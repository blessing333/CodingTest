/*
    1. 터질수있는 뿌요를 발견할수 없을 때 까지 반복
        - board배열에서 터질수 있는 뿌요를 찾는다 (bfs)
        - 터질수있는 뿌요를 찾으면 cnt의 값을 증가시킨다
        - 뿌요를 터트린다
*/
#include<bits/stdc++.h>
using namespace std;
int cnt,dx[]={1,0,-1,0},dy[]={0,1,0,-1};
bool visit[12][6];
char board[12][6];
queue<pair<int,int>> q;
vector<pair<int,int>> v;

void clearPuyo(){
    sort(v.begin(),v.end());
    // for(auto it : v){
    //     cout << "["<<it.first<<"," << it.second<<"]";
    // }
        
    for(auto it : v){
        int c=it.second, r=it.first;
        for(int i=r;i>0;i--){
            board[i][c]=board[i-1][c];
        }
        board[0][c]='.';
    }
    //cout << "\n\n\n";
    // for(int i=0;i<12;i++){
    //     for(int j=0;j<6;j++)
    //         cout << board[i][j];
    //     cout <<"\n";
    // }
    v.clear();
}
/*
    터질수있는 뿌요를 찾는 함수. 터뜨릴수있는 뿌요가 있으면 true, 없으면 false  반환
*/
bool bfs(int x,int y){
    bool isBoom=false;
    int popCount=1;
    v.push_back({x,y});
    visit[x][y]=true;
    q.push({x,y});
    while(!q.empty()){
        pair<int,int> cur=q.front();q.pop();
        for(int i=0;i<4;i++){
            int nx=cur.first+dx[i];
            int ny=cur.second+dy[i];
            if(nx>=12 || nx <0 || ny>=6 ||ny<0)continue;
            if(visit[nx][ny] || board[cur.first][cur.second]!=board[nx][ny]) continue;
            popCount++;
            q.push({nx,ny});
            visit[nx][ny]=true;
            v.push_back({nx,ny});
        }
    }
    if(popCount>=4){
        isBoom=true;
    }
    else{
        for(int i=0;i<popCount;i++)
            v.pop_back();
    }

    return isBoom;

}

int main(){
    bool flag=true;
    for(int i=0;i<12;i++){
        for(int j=0;j<6;j++){
            cin >> board[i][j];
        }
    }
    while(flag){
        flag=false;
        fill(&visit[0][0], &visit[0][0]+12*6,0);
        for(int i=0;i<12;i++){
            for(int j=0;j<6;j++){
                if(board[i][j]!='.' && !visit[i][j]){
                    if(bfs(i,j)){
                        flag=true;
                    }
                }
            }
        }
        if(flag){
            cnt++;
            clearPuyo();
        }
    }
    cout << cnt;
}