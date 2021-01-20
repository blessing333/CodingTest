#include<bits/stdc++.h>
using namespace std;
int dx[]={0,1,1};
int dy[]={1,0,1};
int solution(int m, int n, vector<string> board) {
    int ret=0;
    bool isUpdate=true;
    int cnt=0;
    while(isUpdate){
        vector<pair<int,int>> eraseList;
        isUpdate=false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='0') continue;
                vector<pair<int,int>> tmpList;
                tmpList.push_back({i,j});
                for(int dir=0;dir<3;dir++){
                    int nx=i+dx[dir];
                    int ny=j+dy[dir];
                    if(nx>=m || nx<0 || ny>=n ||ny<0) break;
                    if(board[i][j]!=board[nx][ny]) break;
                    tmpList.push_back({nx,ny});
                }
                if(tmpList.size()>3){
                    isUpdate=true;
                    for(auto it : tmpList){
                        eraseList.push_back(it);
                    }
                }
            }
        }

        for(auto it : eraseList){
            if(board[it.first][it.second]!='0')
                ret++;
            board[it.first][it.second]='0';
        }

        for(int j=0;j<n;j++){
            for(int i=m-1;i>=0;i--){
                if(board[i][j]=='0'){
                    int idx=0;
                    while(i-idx>=0){
                        if(board[i-idx][j]!='0'){
                            board[i][j]=board[i-idx][j];
                            board[i-idx][j]='0';
                            break;
                        }
                        idx++;
                    }
                }
            }
        }
    }
    return ret;
}