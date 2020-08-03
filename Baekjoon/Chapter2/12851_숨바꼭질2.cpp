#include <bits/stdc++.h>
using namespace std;
int n,k;
int dist[100001];
int visit[100001];
int cnt[100001];
queue<int> q;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> k;
    visit[n]=1;
    cnt[n]=1;
    q.push(n);

    while(!q.empty()){
        int cur=q.front();q.pop();
        for(int next : {cur-1,cur+1,cur*2}){
            if(next>=0 && next <=100000){
                if(visit[next]==0){
                    visit[next]=1;
                    dist[next]=dist[cur]+1;
                    q.push(next);
                    cnt[next]=cnt[cur];
                }
                else if(dist[next]==dist[cur]+1){
                    cnt[next]+=cnt[cur];
                }
            }
        }
    }
    
    cout << dist[k] << "\n";
    cout << cnt[k];
}