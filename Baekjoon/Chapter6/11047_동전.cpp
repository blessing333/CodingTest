#include<bits/stdc++.h>
using namespace std;
int n,k,arr[10];
vector<int> v;
int main(){
    cin >> n >> k;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        v.push_back(a);
    }
    
   int index=v.size()-1;
   int sum=0;
   while(k!=0){
        int d=k/v[index];
        sum+=d;
        k-=d*v[index];
        index--;
   }
   cout << sum;
}