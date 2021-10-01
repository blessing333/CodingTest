#include <bits/stdc++.h>

using namespace std;
int v,e,p;
struct Edge{
    int a;
    int w;
    Edge(int b,int c){
        a = b;
        w = c;
    }
    bool operator> (const Edge &e) const{
        return w > e.w;
    }
};

int dijkstra(int a,int b,vector<vector<Edge>> edges){
    vector<int> dist(v+1,INT_MAX);
    dist[a] = 0;
    priority_queue<Edge,vector<Edge>,greater<Edge>> q;
    q.push({a,0});
    while(!q.empty()){
        int cur = q.top().a;
        int curCost = q.top().w;
        q.pop();
        if(curCost > dist[cur]) continue;
        for(auto it : edges[cur]){
            int next = it.a;
            int nextCost = it.w + curCost;
            if(dist[next] > nextCost){
                dist[next] = nextCost;
                q.push({next,nextCost});
            }
        }
    }
    return dist[b];
    
}
int main(){
    cin >> v >> e >> p;
    vector<vector<Edge>> edges(v+1);
    for(int i=0;i<e;i++){
        int a,b,c;
        cin >> a >> b >>c;
        edges[a].push_back(Edge(b,c));
        edges[b].push_back(Edge(a,c));
    }
    int saveRoute = dijkstra(1,p,edges) + dijkstra(p,v,edges);
    int minRoute = dijkstra(1,v,edges);
    string answer = saveRoute <= minRoute ? "SAVE HIM" : "GOOD BYE";
    cout << answer;
    
}