#include <bits/stdc++.h>

using namespace std;
bool cmp(const pair<int,int>&a,const pair<int,int>&b){
    if(a.first < b.first) return false;
    else if(a.first==b.first){
        if(a.second>b.second) return false;
    }
    else return true;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    map<string,int> m;
    map<string,vector<pair<int,int>>> m2;
    vector<pair<int,string>> v;
    vector<int> answer;
   
    for(int i=0;i<genres.size();i++){
        string genre=genres[i];
        int cnt=plays[i];
        m[genre]+=cnt;

        auto iter = m2.find(genre);
        
        if(iter != m2.end()) iter->second.push_back({cnt,i});
        else{
            vector<pair<int,int>> v;
            v.push_back({cnt,i});
            m2.insert({genre,v});
        } 
    }
  
    for(auto it : m) v.push_back({it.second,it.first});
    sort(v.begin(),v.end(),greater<>());
    for(auto it : v){
        string genre=it.second;
        auto iter = m2.find(genre);
        vector<pair<int,int>> tmp;
        tmp = iter->second;
        sort(tmp.begin(),tmp.end(),cmp);
        answer.push_back(tmp[0].second);
        if(tmp.size()>1) answer.push_back(tmp[1].second);
    }

    return answer;
}








  