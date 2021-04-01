#include<bits/stdc++.h>
using namespace std;
int n;
bool isPrime(int n){
    int i = 0;
    int last = n / 2;
    if (n <= 1) return false;
               
    for (i = 2; i <= last; i++){
        if ((n%i) == 0) return false;
    }
    return true;
}

void func(int cnt,int num){
    if(cnt == n){
        cout << num<<"\n";
        return;
    }
    for(int i=0;i<=9;i++){
        int nextNum = num*10 +i;
        if(nextNum == 0 || !isPrime(nextNum)) continue;
        func(cnt+1,nextNum);
    }
}

int main(){
    cin >> n;
    func(0,0);
}