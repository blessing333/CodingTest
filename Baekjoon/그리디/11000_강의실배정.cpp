#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    vector<pair<int,int>> v;
    priority_queue<int,vector<int>,greater<int>> pq;

    for(int i=0;i<n;i++){
        int a, b; cin >> a; cin >> b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end());
    pq.push(v[0].second);
    int answer = 1;
    for(int i=1;i<n;i++){
        if(v[i].first < pq.top()){
            answer++;
            pq.push(v[i].second);
        }
        else{
            pq.pop();
            pq.push(v[i].second);
        }
    }
    cout << answer;
    
}