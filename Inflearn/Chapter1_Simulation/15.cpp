#include<bits/stdc++.h>
using namespace std;
int n;
bool arr[200001];
int main(){
    int cnt=0;
    cin >> n;
    for(int i=2;i<=n;i++)
        arr[i]=true;
    
    for(int i=2;i*i<=n;i++){
        if(arr[i]){
            for(int j=i*2;j<=n;j+=i){
                arr[j]=false;
            }
        }    
    }
    for(int i=2;i<=n;i++){
        if(arr[i])cnt++;
    }
    cout << cnt;
}