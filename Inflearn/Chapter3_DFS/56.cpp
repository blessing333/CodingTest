#include<bits/stdc++.h>
using namespace std;
int n;
void print(int num){
    if(num==0)
        return;
    else{
        print(num-1);
        cout << num << " ";
    }
}

int main(){
    cin >> n;
    print(n);
}