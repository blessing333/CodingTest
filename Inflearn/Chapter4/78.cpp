#include<bits/stdc++.h>
using namespace std;
int vertex,edge,uni[101],cnt;

struct Edge{
    int a,b,w;
    Edge(int v1,int v2,int val){
        a=v1; b=v2; w=val;
    }
    bool operator<(Edge &b)const{
        return w<b.w;
    }
};
vector<Edge> v;

int find(int n){
    if(n==uni[n]) return n;
    else return uni[n]=find(uni[n]);
}

 void integrate(int a,int b){
    a=find(a);
    b=find(b);
    if(a!=b) uni[a]=b;
}

int main(){
    cin >> vertex >> edge;
    for(int i=0;i<edge;i++){
        int a,b,w;
        cin >> a >> b >> w;
        v.push_back(Edge(a,b,w));
    }
    for(int i=1;i<=vertex;i++) uni[i]=i;
    
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        if(find(v[i].a) != find(v[i].b)){
            cnt+=v[i].w;
            integrate(v[i].a,v[i].b);
        }
    }
    cout << cnt;
}
