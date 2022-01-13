#include<bits/stdc++.h>
using namespace std;
int n,m;
int minimum = INT_MAX;
int answer = -1;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    vector<vector<int>> dist(n+1,vector<int>(n+1,5500));
    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b;
        dist[a][b] = 1;
        dist[b][a] = 1;
    }

    for(int i=1;i<=n;i++){
        dist[i][i] = 0;
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
            }
        }
    }

    for(int i=1;i<=n;i++){
        int total = 0;
        for(int j=1;j<=n;j++){
            total += dist[i][j];
        }
        if(minimum > total){
            minimum = total;
            answer = i;
        }
    }

    cout << answer;
}