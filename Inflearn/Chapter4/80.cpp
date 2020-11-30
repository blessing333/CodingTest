#include<bits/stdc++.h>
using namespace std;
int n,m;
struct Edge{
    int v;
    int w;
    Edge(int a,int b){
        v=a;w=b;
    }

    bool operator< (const Edge &a) const{
        return w<a.w;
    }
};
vector<Edge> v[21];

int main(){
    int dist[21];
    priority_queue<Edge> pq;
    fill_n(dist,21,INT_MAX);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b,w;
        cin >> a >> b >>w;
        v[a].push_back(Edge(b,w));
    }
    pq.push(Edge(1,0));
    dist[1]=0;
    while(!pq.empty()){
        Edge cur=pq.top();pq.pop();
        int distance=cur.w;
        if(distance>dist[cur.v]) continue;
        for(int i=0;i<v[cur.v].size();i++){
            if(dist[v[cur.v][i].v] > distance+v[cur.v][i].w){
                dist[v[cur.v][i].v]=distance+v[cur.v][i].w;
                pq.push(Edge(v[cur.v][i].v,v[cur.v][i].w+distance));
            }
        }
    }

    for(int i=1;i<=n;i++){
        if(dist[i]!=INT_MAX)
            cout << i << " : "<<dist[i] << "\n";
        else
            cout << i << " : "<<"impossible" << "\n";
    }
}