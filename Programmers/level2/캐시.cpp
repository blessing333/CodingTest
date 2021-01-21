#include<bits/stdc++.h>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int ret=0;
    deque<string> v;
    if(cacheSize==0) return (int)cities.size() * 5;
    for(int i=0;i<cities.size();i++){
        transform(cities[i].begin(),cities[i].end(),cities[i].begin(),::tolower);
    }

    for(int i=0;i<cities.size();i++){
        //cout << cities[i] <<" : ";
        auto iter = find(v.begin(),v.end(),cities[i]);
        if(iter != v.end()){ // 캐쉬 안에 있을 경우
            //cout << "hit\n";
            ret+=1;
            if(v.size() == cacheSize) v.erase(iter);
            v.push_back(cities[i]);
        }
        else{   //캐쉬 안에 없을 경우
            //cout <<"not hit\n";
            ret+=5;
            if(v.size() == cacheSize) v.pop_front();
            v.push_back(cities[i]);
        }
    }
    return ret;
}