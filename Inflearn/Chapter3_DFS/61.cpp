#include<bits/stdc++.h>
using namespace std;
int arr[11],n,m,cnt;

 void func(int level,int sum){
     if(level==n-1){
         if(sum==m)
            cnt++;
         return;
     }

     else{
         func(level+1,sum+arr[level+1]);
         func(level+1,sum-arr[level+1]);
         func(level+1,sum);
     }
 }
int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    func(-1,0);
    cout << cnt;

}