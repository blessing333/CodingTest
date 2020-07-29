#include<bits/stdc++.h>
#define X first;
#define Y second;

using namespace std;

int t,m,n,k;
int board[55][55];
int visit[55][55];
queue<pair<int,int>> q;

void bfs(int y, int x){
    visit[y][x]=1;
    q.push({y,x});
    
    
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while(t--){
        int result;
        cin >> m >> n >> k;
        fill(&board[0][0],&board[0][0]+55*55,0);
        fill(&visit[0][0],&visit[0][0]+55*55,0);
        while(k--){
            int x,y;
            cin >>  x >> y;
            board[y][x]=1;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;i++){
                if(!visit[i][j] && board[i][j]==1){
                   result++;
                   bfs(i,j);
                }
                    
                
                
                
            }
        }
        
    }
}