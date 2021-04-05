#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    cin >> n;
    priority_queue<int,vector<int>,greater<int>> q;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        q.push(a);
    }
    
    int total =0;
    while(!(q.size() == 1)){
        int op1 = q.top(); q.pop();
        int op2 = q.top(); q.pop();
        int sum= op1+op2;
        q.push(sum);
        total += sum;
    }
    total = n>1 ? total : 0;
    cout << total;
    
}