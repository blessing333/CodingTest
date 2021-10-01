#include<bits/stdc++.h>
using namespace std;
int v,e,cnt=1;
vector<int> history;
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

void go(int a,int start,vector<int> from){
    if(from[a] == start){
        history.push_back(start);
        history.push_back(a);
        cnt++;
        return;
    }
    else {
        go(from[a],start,from);
        history.push_back(a);
        cnt++;
        
    }
}
int main(){
    int start,end;
    cin >> v;
    cin >> e;
    vector<vector<Edge>> edges(v+1);
    vector<int> from(v+1);
    vector<int> dist(v+1,INT_MAX);
    for(int i=0;i<e;i++){
        int a,b,c;
        cin >> a >> b >> c;
        edges[a].push_back(Edge(b,c));
    }
    cin >> start >> end;
    priority_queue<Edge,vector<Edge>,greater<Edge>> q;
    dist[start] = 0;
    q.push({start,0});
    while(!q.empty()){
        int cur = q.top().a;
        int curCost = q.top().w;
        q.pop();
        if(dist[cur] < curCost) continue;
        for(auto it : edges[cur]){
            int next = it.a;
            int nextCost = curCost + it.w;
            if(dist[next] > nextCost){
                dist[next] = nextCost;
                q.push(Edge(next,nextCost));
                from[next] = cur;
            }
        }
    }
    cout << dist[end] <<"\n";
    go(end,start,from);
    cout << cnt<<"\n";
    for(auto it : history){
        cout << it << " ";
    }

    
    
}