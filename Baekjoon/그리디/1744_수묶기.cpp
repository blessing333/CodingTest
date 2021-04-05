#include<bits/stdc++.h>
using namespace std;
int n;
priority_queue<int,vector<int>,less<int>> plusQ;
priority_queue<int,vector<int>,greater<int>> minusQ;
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        if(a > 0) plusQ.push(a);
        else minusQ.push(a);
    }

    int answer =0;
    while(plusQ.size() >1){
        int op1 = plusQ.top(); plusQ.pop();
        int op2 = plusQ.top(); plusQ.pop();
        int sum;
        if(op1 == 1 || op2 == 1) sum= op1 +op2;
        else sum = op1 * op2;
        answer+=sum;    
    }
    if(!plusQ.empty()) answer+=plusQ.top();

    while(minusQ.size() >1){
        int op1 = minusQ.top(); minusQ.pop();
        int op2 = minusQ.top(); minusQ.pop();
        int sum = op1 * op2;
        answer+=sum;    
    }
    if(!minusQ.empty()) answer+=minusQ.top();
    cout << answer;
}