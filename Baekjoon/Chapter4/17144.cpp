#include<bits/stdc++.h>
using namespace std;
int r,c,t;
int board[50][50],dx[]={1,0,-1,0},dy[]={0,1,0,-1};
vector<pair<int,int>> cleaner;
void spread(){
    
    queue<pair<int,int>> q;
    int tmp[50][50];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            tmp[i][j]=board[i][j];
            if(board[i][j]!=0 && board[i][j]!=-1){
                q.push({i,j});
            }
        }
    }
    while(!q.empty()){
        pair<int,int> cur = q.front();q.pop();
        vector<pair<int,int>> v;
        for(int i=0;i<4;i++){
            int nx=cur.first+dx[i];
            int ny=cur.second+dy[i];
            if(nx >= r || nx <0 || ny >=c | ny<0) continue;
            if(board[nx][ny]==-1) continue;
            v.push_back({nx,ny});
        }
        int value=board[cur.first][cur.second]/5;
        int minus=value*v.size();
        tmp[cur.first][cur.second]-=minus;
        for(auto it : v){
            tmp[it.first][it.second]+=value;
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            board[i][j]=tmp[i][j];
        }
    }

    

}
void pure(int cnt){
     int tmp[50][50];
     for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            tmp[i][j]=board[i][j];
        }
    }

    int start_x=cleaner[cnt].first;
    int start_y=cleaner[cnt].second;
    if(cnt==0){
        for(int i=start_y+2;i<c;i++){
            board[start_x][i]=tmp[start_x][i-1];
        }
        board[start_x][start_y+1]=0;
        
        for(int i=start_x-1;i>=0;i--){
            board[i][c-1]=tmp[i+1][c-1];
        }

        for(int i=c-2;i>=0;i--){
            board[0][i]=tmp[0][i+1];
        }

        for(int i=1;i<start_x;i++){
            board[i][start_y]=tmp[i-1][start_y];
        }
    }
    else{
         for(int i=start_y+2;i<c;i++){
            board[start_x][i]=tmp[start_x][i-1];
        }
         board[start_x][start_y+1]=0;

         for(int i=start_x+1;i<r;i++){
            board[i][c-1]=tmp[i-1][c-1];
        }

        for(int i=c-2;i>=0;i--){
            board[r-1][i]=tmp[r-1][i+1];
        }

        for(int i=r-2;i>start_x;i--){
            board[i][0]=tmp[i+1][0];
        }

    }

}
int main(){
    cin >> r >> c >> t;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> board[i][j];
            if(board[i][j]==-1){
                cleaner.push_back({i,j});
            }
        }
    }
    for(int i=0;i<t;i++){
        spread();
        pure(0);
        pure(1);
    }
    //cout << "\n";
    int sum=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            //cout << board[i][j] << " ";
            if(board[i][j]!=-1)
                sum+=board[i][j];
        }
        //cout << "\n";
    }
    //cout << "\n";
    cout << sum;
}