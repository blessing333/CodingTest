#include<bits/stdc++.h>
using namespace std;
int n,arr[10],cnt;
int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        int k=i;
        while(k>0){
            cnt++;
            k/=10;
        }
    }
    cout << cnt;
}