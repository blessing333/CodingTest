#include <bits/stdc++.h>

using namespace std;
stack<pair<int,int>> s;
vector<vector<int>> v;
void func(int n,int a,int b){
    vector<int> tmp;
    if(n == 1){
        tmp.push_back(a);
        tmp.push_back(b);
        v.push_back(tmp);
        return;
    }
    func(n-1,a,6-a-b);
    tmp.push_back(a);
    tmp.push_back(b);
    v.push_back(tmp);
    func(n-1,6-a-b,b);
}

vector<vector<int>> solution(int n) {
    func(n,1,3);
    return v;
}