#include<bits/stdc++.h>
using namespace std;
int n,m,minimum=INT_MAX;
bool check[21];
int board[21][21];

void go(int v,int sum){
    if(v==n){
        minimum=min(sum,minimum);
        return;
    }
    else{
        for(int i=1;i<=n;i++){
            if(!check[i] && board[v][i]){
                check[i]=true;
                go(i,sum+board[v][i]);
                check[i]=false;
            }
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int a,b,w;
        cin >> a >> b >> w;
        board[a][b]=w;
    }
    go(1,0);
    cout << minimum;
}