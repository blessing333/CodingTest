#include<bits/stdc++.h>
using namespace std;
int n,m;
bool check[101];

int main(){
    cin >> n >> m;
    vector<vector<int>> edges(n+1);
    vector<vector<int>> redges(n+1);
    int answer = 0;
    int pos = (n+1)/2;

    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        edges[b].push_back(a);
        redges[a].push_back(b);
    }

    for(int i=1;i<=n;i++){
        int cnt = 0;
        fill_n(check,101,false);
        queue<int> q;
        q.push(i);
        check[i] = true;
        while(!q.empty()){
            int cur = q.front(); q.pop();
            for(auto it : edges[cur]){
                if(check[it]) continue;
                check[it] = true;
                q.push(it);
                cnt++;
            }
        }

        int rcnt = 0;
        queue<int> rq;
        fill_n(check,101,false);
        rq.push(i);
        check[i] = true;
        while(!rq.empty()){
            int cur = rq.front(); rq.pop();
            for(auto it : redges[cur]){
                if(check[it]) continue;
                check[it] = true;
                rq.push(it);
                rcnt++;
            }
        }
        if(cnt >= pos || rcnt >= pos) answer++;
    }

    cout << answer;
}