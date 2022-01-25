#include<bits/stdc++.h>
using namespace std;
int answer = 0;
int n;
bool flag = false;

void func(int a,int cur,vector<int> v){
    if(flag) return;
    if(v.size() == a){
        answer++;
        if(answer == n){
            flag = true;
            for(auto it : v) cout << it;
        }
        return;
    }
    else{
        for(int i=0;i<=9;i++){
            if(i >= cur) break;
            v.push_back(i);
            func(a,i,v);
            v.pop_back();
        }
    }
}

int main(){
    cin >> n;
    if(n == 0){
        cout << 0;
        return 0;
    }
    for(int i=1;i<=10;i++){
        for(int j=1;j<=9;j++){
            vector<int> v(1,j);
            func(i,j,v);
        }
    }
    
    if(!flag) cout << -1;
    
}