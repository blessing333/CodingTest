#include<bits/stdc++.h>
using namespace std;
int n ,arr[100];
stack<int> stk;
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        stk.push(a);
    }

    for(int i=n;i>=1;i--){
        int cnt=stk.top();stk.pop();
        int j;
        for(j=i-1;j<n;j++){
            if(cnt==0){
                arr[j]=i;
                break;
            }
            else{
                if(arr[j+1]>i){
                    arr[j]=arr[j+1];
                    cnt--;
                }
            }
        }
        
    }

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
}