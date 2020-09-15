#include<bits/stdc++.h>
using namespace std;
int n,k;
int dist[100005];
int path[100005];
queue<int> q;
void print(int y){
    if(y==-1)
        return;
    else{
        print(path[y]);
        cout<<y<<" ";
    }
}
int main(){
    cin >> n >> k;
    fill(dist,dist+100005,-1);
    q.push(n);
    dist[n]=0;
    path[n]=-1;
    while(!q.empty()){
        int cur=q.front();q.pop();
        for(int nx : {cur-1,cur+1,cur*2}){
            if(nx>100000 || nx<0)continue;
            if(dist[nx]>-1) continue;
            dist[nx]=dist[cur]+1;
            path[nx]=cur;
            q.push(nx);
        }
    }
    cout << dist[k]<<"\n";
    print(k);
    
    
}