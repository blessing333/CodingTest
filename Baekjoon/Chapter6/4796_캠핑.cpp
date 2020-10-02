#include<bits/stdc++.h>
using namespace std;
int l,p,v,result,cnt=1;
void solve(){
    int d=v/p;
    int s=v%p;
    result=l*d;
    if(s>l) result+=l;
    else result+=s;
    cout << "Case "<<cnt++<<": " <<result<<"\n";
}

int main(){
    while(true){
        cin >> l >> p >> v; 
        if(l==0 && p== 0 && v==0){
            break;
        }
        solve();
    }
}