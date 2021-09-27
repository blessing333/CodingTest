#include <bits/stdc++.h>

using namespace std;
bool check[1005];
unordered_set<int> candi[1005];
vector<int> solution(vector<int> enter, vector<int> leave) {
    int enterIdx = 0;
    int leaveIdx = 0;
    int end = enter.size()-1;
    vector<int> room;

    while(!(enterIdx == end && leaveIdx == end)){
        if(enterIdx > end || leaveIdx > end) break;
        int outer = leave[leaveIdx];
        bool isUpdate = false;

        while(enterIdx <= end && !check[outer]){
            check[enter[enterIdx]] = true;
            room.push_back(enter[enterIdx]);
            enterIdx++;
            isUpdate = true;
        }

        if(isUpdate && room.size() >= 2){
            for(int i=0;i<room.size()-1;i++){
                for(int j=i+1; j<room.size();j++){
                    candi[room[i]].insert(room[j]);
                    candi[room[j]].insert(room[i]);
                }
            }
        }

        auto iter = find(room.begin(),room.end(),outer);
        room.erase(iter);
        check[outer] = false;
        leaveIdx++;
    }

    vector<int> answer;
    for(int i=1;i<=enter.size();i++){
        answer.push_back(candi[i].size());
    }
    return answer;
}