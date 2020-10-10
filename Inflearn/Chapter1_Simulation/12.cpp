#include<bits/stdc++.h>
using namespace std;
int n,c=1,sum,result,d=9;
int main(){
    cin >> n;
    while(sum+d<n){
       sum+=d;
       result=result+c*d;
       c++;
       d*=9;
    }
    result=result+(n-sum)*c;
    cout << result;
}