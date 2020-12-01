#include<bits/stdc++.h>
using namespace std;
int n,minimum=INT_MAX;
vector<int> v[11];
int human[11];
int check[11],visited[11];

pair<int,int> dfs(int idx,int team){
    visited[idx]=1;
    pair<int,int> ret={1,human[idx]};
    for(auto it : v[idx]){
        if(check[it]!=team) continue;//팀이 다르면 스킵
        if(visited[it]) continue;//방문했으면 스킵
        pair<int,int> temp = dfs(it,team);
        ret.first+=temp.first;
        ret.second+=temp.second;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   cin >> n;

   for(int i=1;i<=n;i++){
       cin >>human[i];
   }

   for(int i=1;i<=n;i++){
       int a; cin >> a;
       for(int j=0;j<a;j++){
           int b; cin >> b;
           v[i].push_back(b);
           v[b].push_back(i);
       }
   }

    for(int i=1;i<(1<<n)-1;i++){
        // fill(check, check + 11, 0);
        // fill(visited, visited + 11, 0);
        fill_n(check,11,0);
        fill_n(visited,11,0);
        int idx1=-1,idx2=-1;
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                check[j+1]=1;
                idx1=j+1;
            }
            else{
                idx2=j+1;
            }
        }
        pair<int,int> team1=dfs(idx1,1);
        pair<int,int> team2=dfs(idx2,0);
        if(team1.first+team2.first==n){
            minimum=min(abs(team1.second-team2.second),minimum);
        }
    }
    if(minimum==INT_MAX){
        cout << -1;
    }
    else{
        cout << minimum;
    }
}