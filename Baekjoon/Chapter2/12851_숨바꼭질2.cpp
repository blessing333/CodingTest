#include<bits/stdc++.h>
using namespace std;
int n,k;
int visit[100005];
int dist[100005];
int cnt[100005];
queue<int> q;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> k;
    q.push(n);
    cnt[n]=1;
    visit[n]=true;
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int nx :{cur-1,cur+1,cur*2}){
            if(nx>100000 || nx<0)continue;
            if(!visit[nx]){
                visit[nx]=true;
                dist[nx]=dist[cur]+1;
                q.push(nx);
                cnt[nx]=cnt[cur];
            }
            else if(dist[nx]==dist[cur]+1){
                cnt[nx]+=cnt[cur];
            }
        }
    }
    cout << dist[k] <<"\n";
    cout << cnt[k];
}