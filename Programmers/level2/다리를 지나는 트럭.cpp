#include <bits/stdc++.h>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int cnt=0; // 탈출한 트럭 개수
    int finalPos=truck_weights.size()-1;
    int totalWeight=0;
    int answer = 0;
    int curPos=0; // 대기 트럭 백터에서 어디까지 진행됬는지 나타내는 인덱스
    deque<pair<int,int>> q; //다리를 건너는 트럭 first : 무게 second :위치
    while(cnt<truck_weights.size()){
        answer++;
        int sz=q.size();
        
        for(int i=0;i<sz;i++) q[i].second++;

        if(!q.empty() && q.front().second> bridge_length){ //다리에서 나갈수있는 트럭이 있으면 내보낸다
            totalWeight-=q.front().first;
            q.pop_front();
            cnt++;
        }

        int nextTruckWeight = truck_weights[curPos];
        if(curPos <= finalPos && totalWeight+nextTruckWeight <= weight){ //대기 트럭이 아직 있고 무게가 충분하면 트럭 추가
            int curWeight = truck_weights[curPos++];
            totalWeight+=curWeight;
            q.push_back({curWeight,1});
        }
    }
    return answer;
}