#include<bits/stdc++.h>
using namespace std;
int n,sum;
int main(){
    cin >> n;
    cout << 1;
    for(int i=2;i<n;i++){
        if(n%i==0){
            cout << " + "<<i;
            sum+=i;
        }
    }
    cout << " = "<<sum+1;

}