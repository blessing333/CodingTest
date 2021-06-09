//크루스칼 , union & find
#include<bits/stdc++.h>
using namespace std;
int v,e;
int uni[10002];
struct Edge{
    int v1;
    int v2;
    int cost;
    Edge(int a,int b,int w){
        v1 = a;
        v2 = b;
        cost = w;
    }
    bool operator< (const Edge &a)  const {
        return cost < a.cost;
    }
};

int find(int a){
    if(uni[a] == a) return a;
    else return uni[a] = find(uni[a]);
}

void integrate(int a,int b){
    a = find(a);
    b = find(b);
    if(a != b) uni[b]=a; // a의 루트를 uni[b]에 저장
}

int main(){
    cin >> v >> e;
    int cnt = 0;
    int answer = 0;
    vector<Edge> edges;
    for(int i=0;i<e;i++){
        int a,b,w;
        cin >> a >> b >> w;
        edges.push_back(Edge(a,b,w));
    }
    for(int i=1;i<=v;i++) uni[i] = i;
    sort(edges.begin(),edges.end());
    
    for(int i=0;i<edges.size();i++){
        Edge curEdge = edges[i];
        if(find(curEdge.v1) != find(curEdge.v2)){ //연결되어 있지 않으면
            integrate(curEdge.v1,curEdge.v2);
            answer+=curEdge.cost;
            cnt++;
        }
        if(cnt == v-1) break;
    }
    cout << answer;
}