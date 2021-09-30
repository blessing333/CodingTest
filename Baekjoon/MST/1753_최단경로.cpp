#include<bits/stdc++.h>
using namespace std;
int v,e,start;
struct Edge{
    int a;
    int w;
    Edge(int e,int d){
        a = e;
        w = d;
    }
    bool operator>(const Edge &edge) const{
        return w > edge.w;
    }
};

int main(){
    cin >> v >> e;
    cin >> start;
    vector<vector<Edge>> edges(v+1);
    vector<int> dist(v+1,INT_MAX);
    priority_queue<Edge,vector<Edge>,greater<Edge>> q;
    for(int i=0;i<e;i++){
        int a,b,w;
        cin >> a >> b >> w;
        edges[a].push_back(Edge(b,w));
    }
    dist[start] = 0;
    q.push(Edge(start,0));
    while(!q.empty()){
        int curV = q.top().a;
        int curCost = q.top().w;
        q.pop();
        if(curCost>dist[curV]) continue;
        for(auto it : edges[curV]){
            int dest = it.a;
            int cost = it.w + curCost;
            if(dist[dest] > cost){
                dist[dest] = cost;
                q.push({dest,cost});
            }
        }
    }
    for(int i=1;i<=v;i++){
        if(dist[i] != INT_MAX) cout <<dist[i]<<"\n";
        else cout <<"INF"<<"\n";
    }
}