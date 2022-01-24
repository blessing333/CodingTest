#include <bits/stdc++.h>

using namespace std;
vector<int> edges[17];
vector<int> info;
int answer = 0;
void func(int cur,int s,int w,vector<int> candi){
    int ns= s;
    int nw= w;
    if(info[cur] == 0) ns++;
    else nw++;
    
    if(ns <= nw) return;
    else{
        answer = max(answer,ns);
        candi.erase(remove(candi.begin(),candi.end(),cur),candi.end());
        vector<int> next = candi;
        for(auto it : edges[cur]){
            candi.push_back(it);
        }
        
        for(auto it : candi){
            func(it,ns,nw,candi);
        }
    }
}

int solution(vector<int> v, vector<vector<int>> ed) {
    info = v;
    for(auto it : ed)   edges[it[0]].push_back(it[1]);
    vector<int> tmp;
    func(0,0,0,tmp);
    return answer;
}