/*
    퀸이 서로 공격할 수 없는 조건
        1. 열과 행이 달라야함.
        2. 대각선이 아니어야함.
*/
#include<bits/stdc++.h>
using namespace std;
int n,cnt;
bool check[15];
bool checkRC[40];
bool checkLC[40];

void func(int cur){ //cur번째 행에 말을 배치할 예정
    if(cur==n){
        cnt++;
        return;
    }
    for(int i=0;i<n;i++){
        if(checkRC[cur+i] || checkLC[cur-i+n-1]||check[i])continue;
        checkRC[cur+i]=true;
        checkLC[cur-i+n-1]=true;
        check[i]=true;
        func(cur+1);
        checkRC[cur+i]=false;
        checkLC[cur-i+n-1]=false;
        check[i]=false;
    }
    
}
int main(){
    cin >> n;
    func(0);
    cout << cnt;
}