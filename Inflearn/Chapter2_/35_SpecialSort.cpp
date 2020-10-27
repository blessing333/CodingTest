#include <bits/stdc++.h>
using namespace std;
int n,arr[100];
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j+1]<0){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    
    for (size_t i = 0; i < n; i++){
        cout << arr[i]<< " "; 
    }
    
}
