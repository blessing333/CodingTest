#include<bits/stdc++.h>
using namespace std;
int n,m;
int answer=-1;
bool visited[101];
vector<vector<int>> edge(101);
void dfs(int v){
    visited[v] = true;
    answer++;
    for(auto it : edge[v]){
        if(visited[it]) continue;
        dfs(it);
    }
}

int main(){
    cin >> n;
    cin >> m;
    
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    dfs(1);
    cout << answer;

}