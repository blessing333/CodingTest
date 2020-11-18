#include<bits/stdc++.h>
using namespace std;
int n,m,minimum=INT_MAX;
bool check[21];
vector<pair<int,int>> board[21];
void go(int v,int sum){
    if(v==n){
        minimum=min(minimum,sum);
        return;
    }
    else{
        for(int i=0;i<board[v].size();i++){
            if(check[board[v][i].first]) continue;
            check[board[v][i].first]=true;
            go(board[v][i].first,sum+board[v][i].second);
            check[board[v][i].first]=false;
        }
    }

}
int main(){
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int a,b,w;
        cin >> a >> b >>w;
        board[a].push_back({b,w});
    }
    check[1]=true;
    go(1,0);
    cout << minimum;
}
