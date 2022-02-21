#include <bits/stdc++.h>
using namespace std;
bool visited[20001];
int solution(int n, vector<vector<int>> edge) {
    vector<vector<int>> edges(n+1);
    vector<int> candi;
    for(auto it : edge){
        edges[it[0]].push_back(it[1]);
        edges[it[1]].push_back(it[0]);
    }
    queue<pair<int,int>> q;
    
    int answer = 0;
    int maximum = 0;
    q.push({1,0});
    visited[1] = true;
    
    while(!q.empty()){
        pair<int,int> cur = q.front(); q.pop();
        for(auto it : edges[cur.first]){
            if(visited[it]) continue;
            visited[it] = true;
            int next = cur.second+1;
            if(next > maximum){
                maximum = next;
                candi.clear();
                candi.push_back(it);
            }
            else if(next == maximum){
                candi.push_back(it);
            }
            q.push({it,next});
        }
    }
    return candi.size();
}