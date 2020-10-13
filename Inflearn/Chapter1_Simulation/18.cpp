#include<bits/stdc++.h>
using namespace std;
int n,m,arr[100],maximum=INT_MIN;
int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    int i=0;
    while(i<n){
        bool flag=true;
        int cnt=0;
        while(flag){
            flag=false;
            if(arr[i]>m){
                flag=true;
                cnt++;
            }
            else{
                maximum=max(cnt,maximum);
                cnt=0;
            }
            i++;
            if(i>=n) break;
        }
        
    }
    cout << maximum;
}