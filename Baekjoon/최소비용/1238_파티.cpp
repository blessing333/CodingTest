#include<bits/stdc++.h>
using namespace std;
int v,e,x,maximum;
struct Edge{
    int a;
    int w;
    Edge(int b,int c){
        a = b;
        w = c;
    }
    bool operator> (const Edge & e) const {
        return w > e.w;
    }
};

int dijkstra(int start,int end,vector<vector<Edge>> edges){
    vector<int> dist(v+1,INT_MAX);
    priority_queue<Edge,vector<Edge>,greater<Edge>> q;
    dist[start] = 0;
    q.push({start,0});
    while(!q.empty()){
        int cur = q.top().a;
        int cost = q.top().w;
        q.pop();
        if(dist[cur] < cost) continue;
        for(auto it : edges[cur]){
            int next = it.a;
            int nextCost = cost + it.w;
            if(dist[next] > nextCost){
                dist[next] = nextCost;
                q.push({next,nextCost});
            }
        }
    }
    return dist[end];
}

void getDist(int n,vector<vector<Edge>> edges){
    int a = dijkstra(n,x,edges);
    int b = dijkstra(x,n,edges);
    maximum = a+b >= maximum ? a+b : maximum;
}

int main(){
    cin >> v >> e >> x;
    vector<int> candi;
    vector<vector<Edge>> edges(v+1);
    for(int i=0;i<e;i++){
        int a,b,c;
        cin >> a >> b >> c;
        edges[a].push_back(Edge(b,c));
    }
    for(int i=1;i<=v;i++) getDist(i,edges);
    cout << maximum;
}