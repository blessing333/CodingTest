#include<bits/stdc++.h>
using namespace std;
int n,m;
const int MAXIMUM = 1001*100000;
struct Edge{
    int start;
    int end;
    int cost;
    Edge(int a,int b,int c){
        start = a;
        end = b;
        cost = c;
    }
    bool operator > (const Edge e) const {
        return cost > e.cost;
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    vector<vector<Edge>> edges(n+1);
    vector<int> trace(n+1,0);
    vector<int> dist(n+1,MAXIMUM);
    //1. 우선 최단 경로를 구한다 
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        edges[a].push_back({a,b,c});
        edges[b].push_back({b,a,c});
    }
    
    priority_queue<Edge,vector<Edge>,greater<Edge>> q;

    q.push({0,1,0});
    while(!q.empty()){
        Edge cur = q.top();q.pop();
        int vertex = cur.end;
        int cost =cur.cost;
        if(cost > dist[vertex]) continue;
        for(auto it : edges[vertex]){
            int next = it.end;
            int nextCost = cost + it.cost;
            if(nextCost > dist[next]) continue;
            dist[next] = nextCost;
            q.push({vertex,next,nextCost});
            trace[next] = vertex;
        }
    }

    int end = n;
    vector<pair<int,int>> candi;
    
    while(end != 1){
        int prev = trace[end];
        candi.push_back({prev,end});
        end = prev;
    }
    int before = dist[n];
    int answer = 0;
    for(auto exc : candi){
        for(int i=1;i<=n;i++) dist[i] = MAXIMUM;
        q.push({1,1,0});
        while(!q.empty()){
            Edge cur = q.top();q.pop();
            int vertex = cur.end;
            int cost =cur.cost;
            if(cost > dist[vertex]) continue;
            for(auto it : edges[vertex]){
                int next = it.end;
                int nextCost = cost + it.cost;
                
                if(it.start == exc.first && it.end == exc.second) continue;
                if(nextCost > dist[next]) continue;
                dist[next] = nextCost;
                q.push({vertex,next,nextCost});
                trace[next] = vertex;
            }
        }
        if(dist[n] == MAXIMUM){
            cout << -1;
            return 0;
        }
        else{
            answer = max(answer,dist[n]-before);
        }
    }
    cout << answer;
}
