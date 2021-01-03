#include<bits/stdc++.h>
using namespace std;
bool cmp(const int &a,const int &b){
        return a<b;
    }
int main(){
    vector<int> v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(6);
    v.push_back(7);
    sort(v.begin(),v.end(),less<>());
    for(auto it : v){
        cout << it << " ";
    }
}