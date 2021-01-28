#include<bits/stdc++.h>
using namespace std;
string v;
unordered_map<string,int> m;
void combi(int here,int cnt,string str){
    if(v.size()==cnt){ //사이즈는 2보다 클것
        string temp=v;
        sort(temp.begin(),temp.end());
        m[temp]++;
        return;
    }
    else{
        for(int i=here+1;i<str.size();i++){
            v.push_back(str[i]);
            combi(i,cnt,str);
            v.pop_back();
        }
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> ret;
    for(auto it : orders){
        for(int i=2;i<=it.size();i++){
            combi(-1,i,it);
        }
    }
    for(auto courseSize : course){
        int maximum=0;
        vector<pair<string,int>> candi;
        for(auto it : m){
            if(it.first.size()==courseSize && it.second>=2){
                if(maximum<it.second) maximum=it.second;
                candi.push_back({it.first,it.second});
            }
        }
        for(auto it : candi){
            if(it.second == maximum)
                ret.push_back(it.first);
        }
    }
    sort(ret.begin(),ret.end());
    return ret;
}
