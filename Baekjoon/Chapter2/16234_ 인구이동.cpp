#include<bits/stdc++.h>
using namespace std;
int n,l,r,ret,section;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
queue<pair<int,int>> q;
int board[50][50];
bool update[50][50],visited[50][50];
bool isUpdate=true;
void bfs(int x,int y,int group,int s[],int c[],vector<pair<int,int>> v[]){
    fill(&visited[0][0],&visited[0][0]+2500,false);
    q.push({x,y});
    v[group].push_back({x,y});
    visited[x][y]=true;
    update[x][y]=true;
    int sum=board[x][y];
    c[group]++;
    while(!q.empty()){
        pair<int,int> cur=q.front();q.pop();
        for(int i=0;i<4;i++){
            int nx=cur.first+dx[i];
            int ny=cur.second+dy[i];
            if(nx>=n || nx<0 || ny>=n || ny<0) continue;
            if(visited[nx][ny] && update[nx][ny]) continue;
            int diff=abs(board[cur.first][cur.second]-board[nx][ny]);
            if(diff>=l && diff<=r){
                isUpdate=true;
                q.push({nx,ny});
                update[nx][ny]=true;
                sum+=board[nx][ny];
                c[group]++;
                v[group].push_back({nx,ny});
            }
            visited[nx][ny]=true;
        }
    }
    s[group]=sum;
}

int main(){
    cin >> n >> l >> r;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> board[i][j];
        }
    }
    while(isUpdate){
        int sum[2500],cnt[2500];
        vector<pair<int,int>> vv[2500];
        fill_n(sum,2500,0);
        fill_n(cnt,2500,0);
        isUpdate=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!update[i][j])
                    bfs(i,j,section++,sum,cnt,vv);
            }
        }
        for(int i=0;i<n*n;i++){
            if(vv[i].size()>1){
                int divde=sum[i]/cnt[i];
                for(int j=0;j<vv[i].size();j++){
                    pair<int,int> cur = vv[i][j];
                    board[cur.first][cur.second]=divde;
                }
            }
        }
        if(isUpdate) ret++;
        section=0;
        fill(&update[0][0],&update[0][0]+2500,false);
        // cout <<"sum : " <<sum[2]<<"\n";
        // cout <<"cnt : " <<cnt[2]<<"\n";
        // sort(vv[2].begin(),vv[2].end());
    //     for(auto it: vv[2]){
    //         cout <<"xy : "<<it.first << "," << it.second<<"\n";
    //     }
    //     cout << "\n\n";
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout << board[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    }

    
    cout << ret;
}