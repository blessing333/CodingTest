#include<bits/stdc++.h>
using namespace std;
int n,m,arr[21];
vector<int> board[21];
queue<int> q;
int visit[21];
void bfs(){
    while(!q.empty()){
        int cur=q.front();q.pop();
        vector<int> v=board[cur];
        for(int i=0;i<v.size();i++){
            if(visit[v[i]]>-1) continue;
            visit[v[i]]=visit[cur]+1;
            q.push(v[i]);
        }
    }

}

int main(){
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int a,b;
        cin >> a >>b;
        board[a].push_back(b);
    }
    fill_n(visit,21,-1);
    visit[1]=0;
    q.push(1);
    bfs();
    for(int i=2;i<=n;i++){
        cout << i <<" : "<<visit[i]<<"\n";
    }

}