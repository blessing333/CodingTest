#include<bits/stdc++.h>
using namespace std;
struct Edge{
    int ver;
    int cost;
    Edge(int a,int w){
        ver =a; cost = w;
    }
    bool operator> (const Edge &a) const {
        return cost > a.cost;
    }
};
priority_queue<Edge,vector<Edge>,greater<>> pq;
bool check[200000];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt","rt",stdin);
    //freopen("output.txt","w",stdout);
    while(true){
        int v,e;
        int total = 0;
        int answer = 0;

        cin >> v >> e;
        if(v == 0 && e == 0) break;
        
        vector<Edge> edges[200000];
        for(int i=0; i<v; i++){
            edges[i].clear();
        }
        memset(check,0,sizeof(check));

        for(int i=0;i<e;i++){
            int a,b,w;
            cin >> a >> b >> w;
            total+=w;
            edges[a].push_back(Edge(b,w));
            edges[b].push_back(Edge(a,w));
        }

        pq.push(Edge(0,0));

        while(!pq.empty()){
            Edge cur = pq.top(); pq.pop();
            if(check[cur.ver]) continue;
            check[cur.ver] = true;
            answer += cur.cost;
            for(int i=0;i<edges[cur.ver].size();i++){
                pq.push(Edge(edges[cur.ver][i]));
            }
        }
        cout << total - answer<<"\n";
    }   
}