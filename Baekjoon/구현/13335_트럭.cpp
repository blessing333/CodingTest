#include<bits/stdc++.h>
using namespace std;
int n,w,l;
queue<int> q;
queue<pair<int,int>> bridge; // time, weight
int main(){
    cin >> n >> w >> l;
    for(int i=0;i<n;i++){
        int a; cin >> a;
        q.push(a);
    }
    int curTime = 2;
    int curWeight = 0;
    bridge.push({1,q.front()});
    curWeight += q.front();
    q.pop();

    while(!q.empty()){
        
        int next = q.front();
        pair<int,int> onBridge = bridge.front();

        if(curTime == onBridge.first + w){ // 뺀다
            bridge.pop();
            curWeight -= onBridge.second;
        }
        if(curWeight + next <= l){ // 넣는다
            q.pop();
            bridge.push({curTime,next});
            curWeight += next;
        }
        curTime++;
    }
    cout << curTime + w -1;
}