#include<bits/stdc++.h>
using namespace std;
int n,d,p,sum;
vector<pair<int,int>> v;
priority_queue<int,vector<int>,greater<int>> pq;

int main(){
  
    cin >> n;
    for(int i=0;i<n;i++){
        //second = pay, first=day
        cin >> p >> d;
        v.push_back({d,p});
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        sum += v[i].second;
        pq.push(v[i].second);
        if(v[i].first<pq.size()){
            sum-=pq.top();pq.pop();
        }
    }
    
    cout <<sum;
}