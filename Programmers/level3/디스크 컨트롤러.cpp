#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> jobs) {
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    vector<pair<int,int>> v;
    for(int i=0;i<jobs.size();i++){
        auto it=jobs[i];
        v.push_back({it[0],it[1]});
    }
    sort(v.begin(),v.end()); // 요청 시간을 기준으로 정렬
    vector<pair<int,int>> q;
    int time=0;
    bool isWorking=false;
    int total = 0;
    int pos=0;
    int clearCnt=0;
    while(clearCnt<jobs.size()){
        for(int i=pos;i<v.size();i++){ //현재 시간에 들어올 요청이 있으면 우선순위 큐에 넣어줌
            if(v[i].first<=time){
                pq.push({v[i].second,time});
                pos++;
            }
            else break;
        }

        if(!isWorking && !pq.empty()){ // 일하지 않으면 대기 큐에있는 작업을 작업 큐에 추가
            q.push_back({pq.top().first,pq.top().second});
            pq.pop();
            isWorking = true;
        }
        if(!q.empty())
            q[0].first--;//작업
        
        time++;

        if(!q.empty() && q[0].first==0){
            q.pop_back();
            isWorking=false;
            int value = time-q[0].second;
            total+=value;
            //cout << "value : " << value << " total : " << total <<"\n";
            clearCnt++;
        }
    }
    return total/jobs.size();
}