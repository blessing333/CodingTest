#include<bits/stdc++.h>
using namespace std;
int n,q;
bool visited[5001];
vector<pair<int,int>> arr[5001];
int bfs(int start,int usado){
    int ret = 0;
    fill_n(visited,n+1,false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(auto it : arr[cur]){
            if(visited[it.first]) continue;
            if(it.second < usado) continue;
            q.push(it.first);
            visited[it.first] = true;
            ret++;
        }
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> q;
    for(int i=1;i<=n-1;i++){
        int a,b,c;
        cin >> a >> b >> c;
        arr[a].push_back({b,c});
        arr[b].push_back({a,c});
    }
    
    for(int i=1;i<=q;i++){
        int a,b;
        cin >> a >> b;
        cout << bfs(b,a) <<"\n";
    }
}