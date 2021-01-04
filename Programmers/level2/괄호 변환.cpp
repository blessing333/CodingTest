#include<bits/stdc++.h>
using namespace std;
bool check(string s){
    stack<char> stk;
    stk.push(s[0]);
    for(int i=1;i<s.size();i++){
        char it= s[i];
        if(stk.top()== '('){
            if(it ==')') stk.pop();
            else stk.push(it);
        }
    }
    return stk.size()>0 ? false : true;
}

string func(string w){
    if(w.size()==0) return w;
    string u,v,empty;
    int rightCount=0,leftCount=0,idx;
    for(int i=0;i<w.size();i++){
        if(w[i]=='(') rightCount++;
        else leftCount++;
        u.push_back(w[i]);
        if(leftCount==rightCount){
            idx=i;
            break;
        }
    }
    v=w.substr(idx+1,w.size());
    if(check(u)) {
        return u + func(v);
    }
    else{
        empty.push_back('(');
        empty += func(v);
        empty.push_back(')');
        u=u.substr(1,u.size()-2);
        for(int i=0;i<u.size();i++){
            if(u[i]=='(') u[i]=')';
            else u[i]='(';
        }
        empty+=u;
        return empty;
    }
}

string sulution(string p){
    return func(p);
}

int main(){
    
}