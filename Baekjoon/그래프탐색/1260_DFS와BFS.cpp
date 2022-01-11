#include<bits/stdc++.h>
using namespace std;
int v,e,n;
bool visited[1001];
vector<vector<int>> edge(1001);
void dfs(int s){
    visited[s] = true;
    cout << s <<" ";
    for(auto it : edge[s]){
        if(visited[it]) continue;
        dfs(it);
    }
}

void bfs(){
    queue<int> q;
    cout << n << " ";
    visited[n] = true;
    q.push(n);
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(auto it : edge[cur]){
            if(visited[it]) continue;
            cout << it <<" ";
            visited[it] = true;
            q.push(it);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> v >> e >> n;
    
    for(int i=1;i<=e;i++){
        int a,b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    for(int i=1;i<=v;i++){
        sort(edge[i].begin(),edge[i].end());
    }

    dfs(n);
    cout << "\n";
    for(int i=1;i<=v;i++){
        visited[i] = false;
    }
    bfs();
}
