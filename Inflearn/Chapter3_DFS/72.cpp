#include<bits/stdc++.h>
using namespace std;
int n,k;
queue<int> q;
int main(){
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        q.push(i);
    }
    int cnt=0;
    while(q.size()!=1){
        for(int i =1;i<k;i++){
            q.push(q.front());
            q.pop();
        }
        q.pop();
        // int cur=q.front();q.pop();
        // cnt++;
        // if(cnt==k){
        //     cnt=0;
        //     continue;
        // }
        // q.push(cur);
    }
    cout << q.front();
}