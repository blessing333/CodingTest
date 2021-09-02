#include <bits/stdc++.h>

using namespace std;
int answer = 0;
int cnt = 0;
char dic[] = {'A','E','I','O','U'};
void func(string word, string result, bool flag){
    if(flag) return;
    
    if(word == result){
        flag = true;
        cnt = answer;
        return;
    }
    
    if(result.size() == 5){
        return;
    }
    else{
        for(int i=0;i<5;i++){
            answer++;
            result.push_back(dic[i]);
            func(word,result,flag);
            result.pop_back();
        }
    }
}

int solution(string word) {
    func(word,"",false);
    return cnt;
}