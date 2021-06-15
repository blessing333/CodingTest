#include<bits/stdc++.h>
using namespace std;
struct Vertex{
    double x;
    double y;
    Vertex(){}
    Vertex(double a, double b){
        x = a;
        y = b;
    }
};

struct Edge{
    int start;
    int end;
    double dist;
    Edge(double a, double b,double c){
        start = a;
        end = b;
        dist = c;
    }
    bool operator< (const Edge &a) const{
        return dist < a.dist;
    }
};

vector<int> v;
vector<Edge> edges;
int n;
unordered_map<int,Vertex> m;
int uni[102];

double getDist(int ver1, int ver2){
    double x1 = m[ver1].x;
    double y1 = m[ver1].y;
    double x2 = m[ver2].x;
    double y2 = m[ver2].y;
    return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
}

void combi(int here){
   if(v.size() == 2){
       edges.push_back(Edge(v[0],v[1],getDist(v[0],v[1])));
       return;
   }
   else{
        for(int i=here+1;i<=n;i++){
            v.push_back(i);
            combi(i);
            v.pop_back();
        }
   }
}

int find(int a){
    if(a ==uni[a]) return a;
    else return uni[a] = find(uni[a]);
}

void integrate(int a,int b){
    a = find(a);
    b = find(b);
    if(a!=b) uni[a] = b;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i=1;i<=n;i++){
        double a,b;
        cin >> a >> b;
        m.insert({i,Vertex(a,b)});
        uni[i] = i;
    }
    combi(0);
    sort(edges.begin(),edges.end());
    int cnt = 0;
    double answer = 0;
    for(auto it : edges){
        if(find(it.start) != find(it.end)){
            integrate(it.start,it.end);
            answer+=it.dist;
            cnt++;
        }
        if(cnt == n-1) break;
    }
    cout<<fixed;
    cout.precision(2);
    cout << answer;
    
}