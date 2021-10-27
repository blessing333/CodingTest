#include <bits/stdc++.h>


using namespace std;

int solution(vector<int> food_times, long long k) {
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
    int sz = food_times.size();
    long long sum = 0;
    for(int i=1;i<=sz;i++){
        pq.push({food_times[i-1],i});
        sum+=food_times[i-1];
    }
    if(sum <= k) return -1;
    long long prev = 0;
    long long tmp = k;
    
    while(true){
        pair<long long, int> cur = pq.top();
        long long time = (cur.first-prev) * (long long)pq.size();
        if(time >= tmp) break;
        pq.pop();
        tmp -= time;
        prev = cur.first;
    }
    
    int idx = tmp % pq.size();
    vector<pair<int, long long>> v;
    while(!pq.empty()){
        pair<long long,int> cur = pq.top(); pq.pop();
        v.push_back({cur.second,cur.first});
    }
    sort(v.begin(),v.end());
    return v[idx].first;
    
}