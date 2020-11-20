#include <bits/stdc++.h>
using namespace std;
int dx[]={-1,1,5};
int visit[10000];
queue<int> q;
int main(){
    fill_n(visit,10000,-1);
    int s,e,cnt=0;
    cin >> s >> e;
    q.push(s);
    visit[s]=0;
    while(!q.empty()){
        int cur=q.front();q.pop();
        for(int i=0;i<3;i++){
            int nx=cur+dx[i];
            if(nx<0 || nx >=10000) continue;
            if(visit[nx]>-1) continue;
            visit[nx]=visit[cur]+1;
            if(nx==e) cout << visit[nx];
            q.push(nx);
        }
    }
        
}
