#include <bits/stdc++.h>

using namespace std;

string transform(int num,int n){
    stack<char> stk;
    string result = "";
    if(num == 0) return "0";
    while(num){
        int div = num / n;
        int k = num % n;
        num /=  n;
        if(n >10 && k >= 10) stk.push('A'+(k-10));
        else stk.push('0'+k);
    }
    while(!stk.empty()){
        result.push_back(stk.top());
        stk.pop();
    }
    return result;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    int value = 0;
    int order = 1;
    int cnt = 0;
    while(cnt!=t){
        string s = transform(value,n);
        int size = s.size();
        for(int i=0;i<size;i++){
            if(order == p ){
                answer.push_back(s[i]);
                cnt++;
            }
            if(cnt == t) break;
            order++;
            if(order > m) order=1;
        }
        value++;
    }
    return answer;
}