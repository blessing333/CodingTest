#include<bits/stdc++.h>
using namespace std;
int n;
void func(int num){
    if(num==0)
        return;
    else{
        func(num/2);
        cout << num%2;
    }
}

int main(){
    cin >> n;
    func(n);
}