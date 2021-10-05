#include<bits/stdc++.h>
using namespace std;
int n,q;
const int MAX = 302;

bool checkFriend(int a,int b,vector<pair<int,int>> infos){
    vector<pair<int,int>> v;
    v.push_back(infos[a]);
    v.push_back(infos[b]);
    sort(v.begin(),v.end());
    return v[1].first <= v[0].second;
}

int main(){
    cin >> n;
    vector<pair<int,int>> infos(n+1);
    vector<vector<int>> dist(n+1,vector<int>(n+1,MAX));
    
    for(int i=1;i<=n;i++){
        int a,b;
        cin >> a >> b;
        infos[i] = {a,b};
        dist[i][i] = 0;
    }
    cin >> q;
    vector<pair<int,int>> query;
    for(int i=0;i<q;i++){
        int a,b;
        cin >> a >> b;
        query.push_back({a,b});
    }
    
    for(int i=1;i<n;i++){
        for(int j = i+1; j<=n;j++){
            if(checkFriend(i,j,infos)){
                dist[i][j] = 1;
                dist[j][i] = 1;
            }
        }
    }
    
    for(int k=1; k<= n; k++){
        for(int i=1; i<=n; i++){
            for(int j = 0; j <= n; j++){
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    for(auto it : query){
        int result = dist[it.first][it.second];
        if(result == MAX) cout << -1 <<"\n";
        else cout << result <<"\n";
    }
    
}