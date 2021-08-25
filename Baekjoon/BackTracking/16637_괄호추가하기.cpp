#include<bits/stdc++.h>
using namespace std;
int n; string eval;
int maximum = INT_MIN;
int calc(int n,char oper,int n2){
    switch (oper){
        case '+' : return n+n2;
        case '-' : return n-n2;
        case '*' : return n*n2;
        default : return -1;
    }
}
void func(int idx,int cur){
    if(idx > n-1){
        maximum = max(maximum,cur);
        return;
    }
    else{
        char oper = idx==0 ? '+' : eval[idx-1];
        if(idx +3<=n){
            int pre = calc(eval[idx]-'0',eval[idx+1],eval[idx+2]-'0');
            func(idx+4,calc(cur,oper,pre));
        }
        func(idx+2,calc(cur,oper,eval[idx]-'0'));
    }
}
int main(){
    cin >> n;
    cin >> eval;
    func(0,0);
    cout << maximum;
    
}