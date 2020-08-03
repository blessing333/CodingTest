#include<bits/stdc++.h>
using namespace std;

int dist[100002];
int cnt;
queue<int> q;

int n,k,x;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(NULL);cout.tie(NULL);
    cin >> n >> k ;
    fill(dist,dist+100001,-1);
    dist[n]=0;
    q.push(n);
    while(dist[k]==-1){
        int cur=q.front();
        q.pop();
        for(int next:{cur-1,cur+1,2*cur}){
            if(next<0 || next>100000) continue;
            if(dist[next]!=-1) continue;
            dist[next]=dist[cur]+1;
            q.push(next);
        }
    
    }
    cout << dist[k];
}