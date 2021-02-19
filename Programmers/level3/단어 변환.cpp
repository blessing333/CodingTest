#include <bits/stdc++.h>
using namespace std;
int answer=INT_MAX;
bool check[50];
bool checkCondition(string begin, string target){
    int cnt=0;
    bool result = true;
    for(int i=0 ; i<begin.size();i++){
        if(begin[i] != target[i]){
            cnt++;
            if(cnt > 1){
                result = false;
                break;
            }
        }
    }
    return result;
}

void func(string begin, string target, int cnt,vector<string> words){
    if(begin == target){
        answer = min(answer,cnt);
        return;
    }
    else{
        for(int i=0;i<words.size();i++){
            if(check[i]) continue;
            if(!checkCondition(begin,words[i])) continue;
            check[i]=true;
            func(words[i],target,cnt+1,words);
            check[i]=false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    func(begin,target,0,words);
    if(answer == INT_MAX)
        return 0;
    else return answer;
}
