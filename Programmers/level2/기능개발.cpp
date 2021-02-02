#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    deque<int> dq,dq2;
    vector<int> answer;
    for(int i=0;i<progresses.size();i++){
        dq.push_back(progresses[i]);
        dq2.push_back(speeds[i]);
    }

    while(dq.size()>0){
        for(int i=0;i<dq.size();i++){
            dq[i]+=dq2[i];
        }

        if(dq[0]>=100){
            int cnt=0;
            int idx=0;
            int sz=dq.size();
            for(int i=0;i<sz;i++){
                if(!dq.empty() && dq[0]>=100){
                    cnt++;
                    dq.pop_front();
                    dq2.pop_front();
                }
                else break;
            }
            answer.push_back(cnt);
        }
    }
    return answer;
}