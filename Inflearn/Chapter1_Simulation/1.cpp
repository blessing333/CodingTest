#include<bits/stdc++.h>
using namespace std;
int n,m,total;
int main(){
    cin >> n >> m;
    for(int i=m;i<=n;i+=m){
        total+=i;
    }
    cout << total;
}