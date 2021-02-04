#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int,vector<int>,greater<>> pq;
    for(auto it : scoville){
        pq.push(it);
    }

    bool flag = true;
    int cnt= -1;
    while(flag){
        cnt++;
        int first = pq.top();
        if(first < K){
            pq.pop();
            int second = pq.top();
            pq.pop();
            int newScovile=first+second*2;
            pq.push(newScovile);
        }
        else flag=false;

        if(pq.size()<2 && flag &&pq.top()<K){
            return -1;
        }
    }
    return cnt;
}