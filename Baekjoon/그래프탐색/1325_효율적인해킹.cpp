#include<bits/stdc++.h>
using namespace std;
int n,m;



int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    vector<vector<int>> edges(n+1);
    vector<int> answer;
    int maximum = -1;
    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b;
        edges[b].push_back(a);
    }

    for(int i=1;i<=n;i++){
        queue<int> q;
        bool visited[10001] = {0,};
        visited[i] = true;
        q.push(i);
        int cnt = 0;
        while(!q.empty()){
            int cur = q.front(); q.pop();
            for(auto it : edges[cur]){
                if(visited[it]) continue;
                visited[it] = true;
                q.push(it);
                cnt++;
            }
        }

        if(maximum < cnt){
            answer.clear();
            answer.push_back(i);
            maximum = cnt;
        }
        else if(maximum == cnt){
            answer.push_back(i);
        }
    }
    for(auto it : answer) cout << it << " ";
    
}