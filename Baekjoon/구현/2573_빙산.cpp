#include<bits/stdc++.h>
using namespace std;
int n,m,answer=0;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int board[300][300];
bool visited[300][300];
vector<pair<int,int>> v;

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
            if(board[i][j]>0) v.push_back({i,j});
        }
    }
    int deb=2;
    while(true){ //빙산이 두 덩어리 이상이거나 모든 맵이 다 0이면 종료
        //빙산을 녹인다.
        int cnt = 0;
        answer++;
        //cout << "time : " << answer <<"\n";
        vector<pair<int,int>> v2;
        int tmp[300][300];
        copy(&board[0][0],&board[0][0]+90000,&tmp[0][0]);
       
        for(auto it: v){
            int zeroCount =0;
            for(int i=0;i<4;i++){
                int nx = it.first + dx[i];
                int ny = it.second + dy[i];
                if(nx>= n || nx <0 || ny>= m || ny<0) continue;
                if(board[nx][ny] != 0 ) continue;
                tmp[it.first][it.second]--;
            }
            if(tmp[it.first][it.second] > 0 ) v2.push_back({it.first,it.second});
            else if(tmp[it.first][it.second]<0) tmp[it.first][it.second] = 0;
        }
        copy(&tmp[0][0],&tmp[0][0]+90000,&board[0][0]);
        v=v2;
      
        //덩어리 개수를 샌다
        for(auto it : v){
            if(visited[it.first][it.second]) continue;
            queue<pair<int,int>> q;
            visited[it.first][it.second]=true;
            q.push({it.first,it.second});
            while(!q.empty()){
                pair<int,int> cur = q.front(); q.pop();
                for(int i=0;i<4;i++){
                    int nx = cur.first + dx[i];
                    int ny = cur.second + dy[i];
                    if(nx >= n || nx<0 || ny>= m || ny<0) continue;
                    if(board[nx][ny] < 1 || visited[nx][ny]) continue;
                    visited[nx][ny] = true;
                    q.push({nx,ny});
                }
            }
            cnt++;       
        }
        fill(&visited[0][0],&visited[0][0]+90000,0);
        
        if(cnt >= 2) break;

        bool isAllZero=true;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] != 0){
                    isAllZero=false;
                    break;
                }
            }
        }
        if(isAllZero){
            answer = 0;
            break;
        }
    }
    cout << answer;
}