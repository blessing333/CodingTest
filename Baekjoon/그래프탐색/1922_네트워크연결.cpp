#include<bits/stdc++.h>
using namespace std;
int n,m;
int uni[1001];
struct Edge{
    int s;
    int e;
    int c;
    Edge(int a, int b, int k){
        s=a; e=b; c=k;
    }
    bool operator<(const Edge &a) const{ //오름차순
        return c < a.c;
    }
};
int find(int a){
    if(uni[a] == a) return a;
    else return uni[a] = find(uni[a]);
}

void integrate(int a,int b){ // b를 a에 연결한다
    a=find(a);
    b=find(b);
    if(a!=b)
        uni[a] = b;
}
int main(){
    cin >> n;
    cin >> m;
    vector<Edge> v;
    
    for(int i=1;i<1001;i++){
        uni[i] = i;
    }
    
    for(int i=0;i<m;i++){
        int a,b,c; cin >> a >> b >>c;
        v.push_back(Edge(a,b,c));
    }
    sort(v.begin(),v.end());
  
    int answer = 0;
    int cnt=0;
    for(auto it : v){
        if(cnt== n-1) break;
        if(find(it.s) != find(it.e)){
            integrate(it.s,it.e);
            answer += it.c;
            cnt++;
        }
    }
    cout <<answer;
}