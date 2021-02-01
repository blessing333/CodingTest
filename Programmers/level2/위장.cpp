#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string,int> m;
    int answer = 1;
    for(auto it : clothes){
        string categories = it[1];
        m[categories]++;
    }
    for(auto it : m){
        answer*= (it.second+1);
    }
    return answer-1;
}