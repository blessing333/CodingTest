#include <bits/stdc++.h>

using namespace std;
int tc;

int main(){
    cin >> tc;
    while(tc--){
        int cnt = 0;
        int n,d,start; 
        cin >> n >> d >> start;
        vector<int> dist(n+1,100000001);
        vector<bool> infect(n+1,false);
        vector<vector<pair<int,int>>> edges(n+1);
        for(int i=0;i<d;i++){
            int a,b,s;
            cin >> a >> b >> s;
            edges[b].push_back({s,a});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        pq.push({0,start});
        infect[start] = true;
        while(!pq.empty()){
            pair<int,int> cur = pq.top(); pq.pop();
            int cost = cur.first;
            int vertex = cur.second;
            if(dist[vertex] < cost) continue;
            for(auto it : edges[vertex]){
                int next = it.second;
                int nextCost = it.first + cost;
                if(dist[next] > nextCost){
                    dist[next] = nextCost;
                    infect[next] = true;
                    pq.push({nextCost,next});
                }
            }
        }
        int maximum = 0;
        for(int i=1;i<=n;i++){
            if(infect[i]) cnt++;
            if(dist[i] != 100000001)
                maximum = max(maximum,dist[i]);
        }
        cout << cnt <<" " <<maximum<<"\n";
    }
    
}