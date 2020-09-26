#include<bits/stdc++.h>
using namespace std;
int result,n;
int arr[100];
int main(){
    
    int maximum=INT_MIN;
    int minimum=INT_MAX;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    for(int i=0;i<n;i++){
        maximum=max(maximum,arr[i]);
        minimum=min(minimum,arr[i]);
    }
    result=maximum-minimum;
    cout << result;
    
    

}