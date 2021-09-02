#include <bits/stdc++.h>

using namespace std;
bool comp(const pair<int,string> &a , const pair<int,string> &b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    else return a.first > b.first;
}

vector<string> tokenizing(string str){
    stringstream ss(str);
    vector<string> result;
    string token;
    while(getline(ss,token,' ')){
        result.push_back(token);
    }
    return result;
}

string solution(vector<string> table, vector<string> languages, vector<int> preference) {
    vector<pair<int,string>> list;
    vector<string> info;
    for(string depart : table){
        info = tokenizing(depart);
        int total = 0;
        for(int i=0;i<languages.size();i++){ // 점수 계산
            for(int j = 1; j<info.size(); j++){
                if(info[j] == languages[i]){
                    total += preference[i] * (6-j);
                }
            }
        }
        list.push_back({total,info[0]});
        info.clear();
    }
    sort(list.begin(),list.end(),comp);
    return list[0].second;
}