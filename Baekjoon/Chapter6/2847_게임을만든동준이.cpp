#include<bits/stdc++.h>
using namespace std;
int n,arr[105],result;

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    for(int i=n-1;i>0;i--){
        if(arr[i]<=arr[i-1]){
            int diff=arr[i-1]-arr[i]+1;
            arr[i-1]=arr[i]-1;
            result+=diff;
        }
    }
    cout << result;
}