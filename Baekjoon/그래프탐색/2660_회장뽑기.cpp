#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> edge(51);
int minimum = INT_MAX;
vector<int> candi;
int bfs(int v){
    bool visited[51] = {0,};
    queue<int> q;
    visited[v] = true;
    q.push(v);
    int level = -1;
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            int cur = q.front(); q.pop();
            for(auto it : edge[cur]){
                if(visited[it]) continue;
                visited[it] = true;
                q.push(it);
            }
        }
        level++;
    }
    return level;
}
int main(){
    cin >> n;
    int a,b;
    while(true){
        cin >> a >> b;
        if(a == -1 && b == -1) break;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    for(int i=1;i<=n;i++){
        int res = bfs(i);
        if(res < minimum){
            minimum = res;
            candi.clear();
            candi.push_back(i);
        }
        else if(res == minimum){
            candi.push_back(i);
        }
    }
    cout << minimum << " " << candi.size() << "\n";
    sort(candi.begin(),candi.end());
    for(auto it : candi){
        cout << it << " ";
    }

}