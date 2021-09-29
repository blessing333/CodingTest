#include<bits/stdc++.h>
using namespace std;
int n,m;
int dx[] = {-1,1};
int visited[100001];
int main(){
    cin >> n >> m;
    queue<int> q;
    q.push(n);
    for(int i=0;i<=100000;i++) visited[i] = -1;
    visited[n] = 0;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        if(cur == m){
            cout <<  visited[cur];
            return 0;
        }

        int nx = cur * 2;
        if(!(nx < 0 || nx >= 100001 || visited[nx] > -1)){
            visited[nx] = visited[cur];
            q.push(nx);
        }

        for(int i=0;i<2;i++){
            int nx = cur + dx[i];
            if(nx < 0 || nx >= 100001 || visited[nx] > -1) continue;
            visited[nx] = visited[cur] +1;
            q.push(nx);
        }
    }
}