#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    priority_queue<int> q;

    for(int i=0;i<n;i++){
        int num; cin >> num;
        q.push(num);
    }
    
    long long maximum = q.top();q.pop();
    int cnt = 1;
    while(!q.empty()){
        int weight = q.top(); q.pop();
        cnt++;
        long long candi = weight * cnt;
        maximum = max(maximum,candi);
    }
    cout << maximum;
}