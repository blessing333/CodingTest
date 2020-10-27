#include<bits/stdc++.h>
using namespace std;
int n,arr[100];
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    for(int i=1;i<n;i++){
        int tmp=arr[i];
        int j;
        for(j=i-1;j>=0;j--){
            if(arr[j]>tmp){
                arr[j+1]=arr[j];
            }
            else
                break;
        }
        arr[j+1]=tmp;
    }

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
}