#include<bits/stdc++.h>
using namespace std;
int n,arr[100];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    for(int i=0;i<n-1;i++){
        int idx=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[idx]){
                idx=j;
            }
        }
        swap(arr[i],arr[idx]);
    }

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    
}