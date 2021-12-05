#include<bits/stdc++.h>
using namespace std;
int r,c;
int sx,sy;
int dx[] = {1,1,1,0,0,0,-1,-1,-1};
int dy[] = {-1,0,1,-1,0,1,-1,0,1};
char board[100][100];
int cnt[100][100];
vector<pair<int,int>> v;
int main(){
    bool flag = false;
    int idx = -1;
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> r >> c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> board[i][j];
            if(board[i][j] == 'R'){
                v.push_back({i,j});
                cnt[i][j]++;
            }
            else if(board[i][j] == 'I') {
                sx = i; sy = j;
            }
            
        }
    }
    string str;
    cin >> str;
    int sz = str.size();
    for(int i=0;i<sz;i++){
        int dir = str[i] - '1';
        int nnx = sx+ dx[dir];
        int nny = sy + dy[dir];
        if(board[nnx][nny] == 'R'){
            cout << "kraj "<< i+1;
            flag = true;
            idx = i;
            break;
        }
        board[sx][sy] = '.';
        board[nnx][nny] = 'I';
        sx = nnx;
        sy = nny;
        
        for(auto it : v){
            int minimum = INT_MAX;
            int nx = it.first;
            int ny = it.second;
            for(int j=0;j<9;j++){
                int cx = it.first + dx[j];
                int cy = it.second + dy[j];
                if(cx >= r || cx<0 || cy>= c || cy<0) continue;
                int dist = abs(sx-cx) + abs(sy-cy);
                if(dist < minimum){
                    minimum = dist;
                    nx = cx; ny = cy;
                }
            }

            board[it.first][it.second] = '.';
            cnt[it.first][it.second]--;
            cnt[nx][ny]++;
            if(board[nx][ny] == 'I'){
                cout << "kraj "<< i+1;
                flag = true;
                break;
            }
        }

        if(flag) break;
        
        v.clear();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(cnt[i][j] == 1){
                    board[i][j] = 'R';
                }
                else if(cnt[i][j] >= 2){
                    cnt[i][j] = 0;
                    board[i][j] = '.';
                }
                
                if(board[i][j] == 'R') v.push_back({i,j});
            }
        }

        // cout <<"\n";
        // for(int i=0;i<r;i++){
        //     for(int j=0;j<c;j++){
        //         cout << board[i][j];
        //     }
        //     cout << "\n";
        // }
    }
    
    if(!flag){
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cout << board[i][j];
            }
            cout << "\n";
        }
    }
    
    
}