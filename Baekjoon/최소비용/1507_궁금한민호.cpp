#include<bits/stdc++.h>
using namespace std;
int n;
int dist[21][21];
bool check[21][21];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> dist[i][j];
            check[i][j] = true;
        }
    }
    
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i == k || j == k) continue;
                int a = dist[i][j];
                int b = dist[i][k] + dist[k][j];
                if(a == b) check[i][j] = false;
                else if(a > b){
                    cout << -1;
                    return 0;
                }
            }
        }
    }
    int answer = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(check[i][j]) answer += dist[i][j];
        }
    }
    cout << answer/2;
}