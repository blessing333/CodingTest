#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> priorities, int location) {
    deque<pair<int,int>> q;
    int cnt=1;
    for(int i=0;i<priorities.size();i++){
        q.push_back({priorities[i],i});
    }
    while(true){
        int sz = q.size();
        bool shouldPop=true;
        for(int i=1;i<sz;i++){
            if(q.size()>1 && q[0].first < q[i].first){
                rotate(q.begin(),q.begin()+1,q.end());
                shouldPop=false;
                break;
            }
        }
        
        if(shouldPop){
            if(q.front().second == location)    return cnt;
            q.pop_front();
            cnt++;
        }
    }
}