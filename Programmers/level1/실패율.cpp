#include<bits/stdc++.h>

using namespace std;
bool cmp(const pair<double,int> &a, const pair<double, int> &b){
    if(a.first==b.first) return a.second<b.second;
    else return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    int reach[501]={0,};
    int clear[501]={0,};
    vector<pair<double,int>> v;
    vector<int> answer;
    for(auto it : stages){
        for(int i=1;i<=it;i++){
            reach[i]++;
            if(i!=it){
                clear[i]++;
            }
        }
    }
    for(int i=1;i<=N;i++){
        double failRate;
        if(reach[i]==0){
            failRate=0;
        }
        else{
            failRate=(double)(reach[i]-clear[i])/reach[i];
        }
        v.push_back({failRate,i});
    }

    sort(v.begin(),v.end(),cmp);
    for(auto it : v){
        answer.push_back(it.second);
    }
    return answer;
}