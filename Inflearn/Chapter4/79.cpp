#include<bits/stdc++.h>
using namespace std;
struct Edge{
    int v;int w;
    Edge(int a, int b){
        v=a;w=b;
    }
    bool operator>(const Edge &a)const{
        return w>a.w;
    }
};
vector<Edge> v[101];
bool check[101];
priority_queue<Edge,vector<Edge>,greater<Edge>> pq;
int main(){
    int n,m,result=0;
    cin >> n >>m;
    for(int i=0;i<m;i++){
        int a,b,w;
        cin >> a >> b >>w;
        v[a].push_back(Edge(b,w));
        v[b].push_back(Edge(a,w));
    }
    pq.push(Edge(1,0));
    while(!pq.empty()){
        Edge cur=pq.top();pq.pop();
        int nextVertex=cur.v,cost=cur.w;
        if(check[nextVertex])continue;
        check[nextVertex]=true;
        result+=cost;
        for(int i=0;i<v[nextVertex].size();i++){
            pq.push(v[nextVertex][i]);
        }

    }
    cout << result;
}