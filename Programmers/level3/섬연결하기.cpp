#include <bits/stdc++.h>
using namespace std;
int uni[101];
struct Edge{
    int v1; int v2;int cost;
    Edge(int a,int b, int c){
        v1=a; v2=b; cost=c;
    }
    bool operator<(const Edge &b)const{
        return cost<b.cost;
    }
};

int find(int i){
    if(uni[i]==i) return i;
    else return uni[i] = find(uni[i]);
}

void integrate(int a, int b){
    a=find(a);
    b=find(b);
    if(a!=b) uni[a]=b;
}
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<Edge> v;
    for(int i=1;i<=n;i++) uni[i]=i;
    for(auto it : costs){
        v.push_back(Edge(it[0],it[1],it[2]));
    }
    sort(v.begin(),v.end());
    for(auto it : v){
        if(find(it.v1)!=find(it.v2)){
            answer+=it.cost;
            integrate(it.v1,it.v2);
        }
    }

    return answer;
}