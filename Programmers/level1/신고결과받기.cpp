#include <bits/stdc++.h>

using namespace std;
unordered_map<string,int> idMap;
unordered_map<string,int> mailMap;
set<string> repot[1000];

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    int id = 0;
    for(string it : id_list){
        mailMap.insert({it,0});
        idMap[it] = id;
        id++;
    }
    
    for(auto it : report){
        string token;
        vector<string> result;
        stringstream ss(it);
        while(getline(ss,token,' ')){
            result.push_back(token);
        }
        string reporter = result[0];
        int targetId = idMap[result[1]];
        repot[targetId].insert(reporter);
    }
    
    int sz = id_list.size();
    vector<int> answer;
    for(int i=0;i<sz;i++){
        if(repot[i].size() >= k){
            for(auto it : repot[i]){
                mailMap[it]++;
            }
        }
    }
    
    for(auto it : id_list){
        int cnt = mailMap[it];
        answer.push_back(cnt);
    }
    return answer;
}