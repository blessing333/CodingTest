#include<bits/stdc++.h>
using namespace std;
int k;

void func(set<int> v,int cnt,vector<int> candi,int n){
    if(cnt == 6){
        for(auto it : candi) cout << it << " ";
        cout <<"\n";
        return;
    }
    else{
        for(int i=n+1;i<v.size();i++){
            auto iter = v.begin();
            advance(iter,i);
            candi.push_back(*iter);
            func(v,cnt+1,candi,i);
            candi.pop_back();
        }
    }
}
int main(){
    while(true){
        set<int> v;
        vector<int> candi;
        cin >> k;
        if(k == 0) break;
        for(int i=0;i<k;i++){
            int a; cin >> a;
            v.insert(a);
        }
        func(v,0,candi,-1);
        cout <<"\n";
    }
}