#include<bits/stdc++.h>
using namespace std;
int n,e;
struct Edge{
    int a;
    int w;
    Edge(int s,int d){
        a = s;
        w = d;
    }
    bool operator>(const Edge &e) const {
        return w > e.w;
    }
};
int dijkstra(int start,int dest,vector<vector<Edge>> edges){
    vector<int> dist(n+1,INT_MAX);
    priority_queue<Edge,vector<Edge>,greater<Edge>> q;
    dist[start] = 0;
    q.push(Edge(start,0));
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
                q.push(Edge(next,nextCost));
            }
        }
    }
    return dist[dest] != INT_MAX ? dist[dest] : -1;
}

int main(){
    cin >> n >> e;
    vector<vector<Edge>> edges(n+1);
    for(int i=0;i<e;i++){
        int a,b,c;
        cin >> a >> b >> c;
        edges[a].push_back(Edge(b,c));
        edges[b].push_back(Edge(a,c));
    }
    int via,via2;
    int answer;
    int answer2;
    cin >> via >>via2;

    int a = dijkstra(1,via,edges);
    int b = dijkstra(via,via2,edges);
    int c = dijkstra(via2,n,edges);
    //cout <<"\n" << a <<"    "<< b <<"   "<<c<<"\n";
    if(a == -1 || b == -1 || c == -1) answer = -1;
    else answer = a+b+c;

    a = dijkstra(1,via2,edges);
    b = dijkstra(via2,via,edges);
    c = dijkstra(via,n,edges);
    if(a == -1 || b == -1 || c == -1) answer2 = -1;
    else answer2 = a+b+c;

    if(answer == -1 && answer2 == -1) cout << -1;
    else if(answer < 0 || answer2 < 0) cout << max(answer,answer2);
    else cout << min(answer,answer2);
}