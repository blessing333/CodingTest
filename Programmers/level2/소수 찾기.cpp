#include <bits/stdc++.h>

using namespace std;
unordered_set<int> m;
bool check[7];
int answer=0;
string v;
void permu(int cnt,string str){
    if(v.size() == cnt){
        int value = stoi(v);
        if(value == 2){
            m.insert(value);
            return;
        }
        if(value<2) return;
        for(int i=2;i<value;i++){
            if(value%i ==0 ) return;
        }
        m.insert(value);
        return;
    }
    else{
        for(int i=0;i<str.size();i++){
            if(check[i]) continue;
            check[i]=true;
            v.push_back(str[i]);
            permu(cnt,str);
            check[i]=false;
            v.pop_back();
        }
    }
}

int solution(string numbers) {
    int sz=numbers.size();
    for(int i=1;i<=sz;i++){
        permu(i,numbers);
    }
    
    return (int)m.size();
}