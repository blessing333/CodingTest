#include <bits/stdc++.h>

using namespace std;
string divide(int num,int k){
    vector<int> v;
    string ret;
    while(num >= 1){
        int s = num % k;
        num /= k;
        v.push_back(s);
    }
    int sz = v.size();
    for(int i= sz-1;i>=0;i--) ret.push_back(v[i]+'0');
    return ret;
}

bool isPrime(string str){
    long long num = stoll(str);
    if(num == 1) return false;
    if(num == 2) return true;
    for(long long i=2;i*i <=num; i++){
        if(num % i == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    string str = divide(n,k);
    // cout << str <<"\n";
    vector<int> v;
    int sz = str.size();
    for(int i=0;i<sz;i++){
        if(str[i] == '0') v.push_back(i);
    }
    v.push_back(sz-1);
    int before = 0;
    int answer = 0;
    for(auto it : v){
        string num;
        for(int i = before; i<= it;i++){
            char c = str[i];
            if(c == '0') continue;
            num.push_back(c);
        }
        // cout <<"str : " << num <<"\n";
        if(num.size() > 0 && isPrime(num)) answer++;
        before = it;
    }
    
    return answer;
}