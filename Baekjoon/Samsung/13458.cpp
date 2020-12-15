#include<bits/stdc++.h>
using namespace std;
int n,b,c,ret;
vector<int> v;
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        int k; cin >> k;
        v.push_back(k);
    }
    cin >> b >> c;
    for(auto it : v){
        bool isUsed=false;
        if(!isUsed){
            it-=b;
            isUsed=true;
            ret++;
            //cout<<"total - main : " <<it <<"\n";
        }
        if(it>0){
            int sub=it/c;
            if(it%c!=0) sub++;
            ret+=sub;
        }
    }
    cout << ret;
}