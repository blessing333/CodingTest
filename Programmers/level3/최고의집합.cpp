#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    if(n > s){
        answer.push_back(-1);
        return answer;
    }
    
    int base = s / n;
    int div = s % n;
    
    
    for(int i=0;i<n;i++){
        answer.push_back(base);
    }
    for(int i=0;i<div;i++){
        answer[i]++;
    }
    sort(answer.begin(),answer.end());
    return answer;
}