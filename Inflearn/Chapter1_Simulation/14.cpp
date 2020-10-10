#include<bits/stdc++.h>
using namespace std;
int n;
stack<char> stk;
bool isPrime(int x){
    if(x==1)
         return false;
    for(int i=2;i<x;i++){
        if(x%i==0){
            return false;
        }
    }
        return true;
}
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        string num,str;
        cin >> num;
        for(int i=num.size()-1;i>=0;i--){
            
                str+=(num[i]);
        }
        int k=stoi(str)+0;
        if(isPrime(k)){
            cout << k << " ";
        }
    }
}