#include<bits/stdc++.h>
using namespace std;
int dy[21][21];
int func(int n,int r){
    if(dy[n][r]) return dy[n][r];
    if(n==r || r==0) return 1;
    else return dy[n][r]= func(n-1,r)+func(n-1,r-1);
}

int main(){
    int n,r;
    cin >> n >> r;
    cout << func(n,r);
}
