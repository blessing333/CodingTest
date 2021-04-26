#include<bits/stdc++.h>
using namespace std;
int n;
stack<int> stk;
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        if(a == 0) stk.pop();
        else stk.push(a);
    }
    int total =0;
    while(!stk.empty()){
        total += stk.top();
        stk.pop();
    }
    cout << total;
}