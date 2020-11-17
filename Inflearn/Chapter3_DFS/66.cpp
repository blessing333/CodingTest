#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
vector<int> arr[21];
bool check[21];
void go(int v){
    if(v==n){
        cnt++;
        return;
    }
    else{
        for(int i=0;i<arr[v].size();i++){
            if(check[arr[v][i]]==0){
                check[arr[v][i]]=true;
                go(arr[v][i]);
                check[arr[v][i]]=false;
            }
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int r,c;
        cin >> r >> c;
        arr[r].push_back(c);
    }
    check[1]=true;
    go(1);
    cout << cnt;
}