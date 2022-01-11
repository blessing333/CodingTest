#include<bits/stdc++.h>
using namespace std;
int n,m;
bool visited[1001];
int main(){
    cin >> n >> m;
    vector<vector<int>> edge(n+1);
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    int answer = 0;
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(visited[i]) continue;
        answer++;
        visited[i] = true;
        q.push(i);
        while(!q.empty()){
            int cur = q.front();q.pop();
            for(auto it : edge[cur]){
                if(visited[it]) continue;
                visited[it] = true;
                q.push(it);
            }
        }

    }
    cout << answer;

    
}