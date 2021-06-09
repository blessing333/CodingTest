//프림 , priority_queue
#include<bits/stdc++.h>
using namespace std;
int v,e;
struct Edge{
    int v;
    int cost;
    Edge(int a, int w){
        v = a; cost = w;
    }
    bool operator> (const Edge &a) const{
        return cost > a.cost;
    }
};
int main(){
    cin >> v >> e;
    vector<Edge> edges[10002];
    priority_queue<Edge,vector<Edge>,greater<Edge>> pq;
        
    for(int i=0;i<e;i++){
        int a,b,w;
        cin >> a >> b >> w;
        edges[a].push_back(Edge(b,w));
        edges[b].push_back(Edge(a,w));
    }

    pq.push(Edge(1,0));
    bool check[10002];
    int answer = 0;
    while(!pq.empty()){
        Edge cur = pq.top(); pq.pop();
        int nextVertex = cur.v;
        if(check[cur.v]) continue;
        answer+=cur.cost;
        check[nextVertex] = true;
        for(int i=0;i<edges[nextVertex].size();i++){
            pq.push(edges[nextVertex][i]);
        }
    }
    cout << answer;
}