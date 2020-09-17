/*
    1.인접한 번호끼리 스타를 한다.
    2. 참가자가 홀수라면 마지막 번호는 부전승
*/
#include<bits/stdc++.h>
using namespace std;
int n,m,k,cnt=1,anw = -1;

int main(){
    cin >> n >> m >> k;
    while(n){
        if((m+1)/2==(k+1)/2){
            anw=cnt;
            break;
        }
        m=(m+1)/2;
        k=(k+1)/2;
        n=n/2;
        cnt++;
    }
    cout << anw;   
}