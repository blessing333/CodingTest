/*
    1. n명의 왕자를 벡터에 저장한다.
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int n,k,arr[1001],bp;
int main(){
    cin >> n >> k;
    int idx=0;
    int cnt=0;
    while(bp!=n-1){
        idx++;
        if(idx>n) idx=1;
        if(arr[idx]==0){
            cnt++;
            if(cnt==k){
                arr[idx]=1;
                cnt=0;
                bp++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(arr[i]==0){
            cout << i;
            break;
        }
    }
}