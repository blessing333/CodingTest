#include<bits/stdc++.h>
using namespace std;
int board[50][50];
int tmp[50][50];
bool check[50][50];
vector<pair<int,int>> cloud;
int dx[8] = {0,-1,-1,-1,0,1,1,1};
int dy[8] = {-1,-1,0,1,1,1,0,-1};
int n,m;
vector<pair<int,int>> v;

void waterIncrease(){
    for(auto it : cloud){
        int cnt = 0;
        for(int i=1;i<8;i+=2){
            int nx = it.first + dx[i];
            int ny = it.second + dy[i];
            if(nx >= n || nx < 0 || ny >= n || ny < 0) continue;
            if(tmp[nx][ny] > 0) cnt++;
        }
        board[it.first][it.second] += cnt;
    }
}

void move(int d,int s){
    s= s%n;
    for(auto &it : cloud){
        it.first = (it.first + s * dx[d] +n) % n;
        it.second = (it.second + s * dy[d] + n) % n;
    }
}

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> board[i][j];
            tmp[i][j] = board[i][j];
        }
    }
    cloud.push_back({n-1,0});
    cloud.push_back({n-1,1});
    cloud.push_back({n-2,0});
    cloud.push_back({n-2,1});

    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        a--;
        v.push_back({a,b});
    }
    for(auto it : v){
        int d = it.first;
        int s = it.second;
        
        move(d,s);
        for(auto it : cloud){
            board[it.first][it.second]++;
            tmp[it.first][it.second]++;
            check[it.first][it.second] = true;
        }

        waterIncrease();

        cloud.clear();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] >= 2 && !check[i][j]){
                    cloud.push_back({i,j});
                    board[i][j]-=2;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                check[i][j] = false;
                tmp[i][j] = board[i][j];
            }
        }
    }

    int answer = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            answer+=board[i][j];
        }
    }
    
    cout << answer;

}