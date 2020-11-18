#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
vector<int> board[8];
bool visit[8];
queue<int> q;
void bfs(){
    while(!q.empty()){
        int cur=q.front();q.pop();
        cout << "cur : "<<cur << "\n";
        for(int i=0;i<board[cur].size();i++){
            if(visit[board[cur][i]]) continue;
            visit[board[cur][i]]=true;
            q.push(board[cur][i]);
        }
    }
}

int main(){
    for(int i=1;i<=6;i++){
        int a,b;
        cin >> a >> b;
        board[a].push_back(b);
    }
    visit[1]=true;
    q.push(1);
    bfs();
    
}