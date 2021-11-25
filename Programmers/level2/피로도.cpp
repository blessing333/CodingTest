#include <bits/stdc++.h>

using namespace std;
vector<int> v;
bool check[8];
int answer = -1;
void permu(int k,int sz,vector<vector<int>> dungeons){
    if(v.size() == sz) {
        int tmp = k;
        int cnt = 0;
        for(auto it : v){
            if(dungeons[it][0] <= tmp){
                cnt++;
                tmp-=dungeons[it][1];
            }
            else break;
        }
        answer = max(answer,cnt);
    }
    for(int i=0;i<sz;i++){
        if(check[i]) continue;
        check[i] = true;
        v.push_back(i);
        permu(k,sz,dungeons);
        v.pop_back();
        check[i] = false;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int sz =dungeons.size();
    permu(k,sz,dungeons);
    return answer;
}