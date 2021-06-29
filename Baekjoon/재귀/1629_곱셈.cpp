#include<bits/stdc++.h>
using namespace std;
int a,b,c;

long long func(int a,int n,int c){
    if(n == 0) return 1;
    long long half = func(a,n/2,c);
    if(n%2 == 0) return half * half %c;
    else return ((half*half)%c)*a%c;
}
int main(){
    cin >> a >> b >>c;
    cout << func(a%c,b,c);
}
