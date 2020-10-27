#include<bits/stdc++.h>
using namespace std;
int n,m,arr[10];
void LRU(int job){
    bool search=false;
    int idx=n-1;
   for(int i=0;i<n;i++){
       if(arr[i] == job){
           search=true;
           idx=i;
        }
    }

    for(int i=idx-1;i>=0;i--){
        arr[i+1]=arr[i];
    }

    arr[0]=job;
}

int main(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int job;
        cin >> job;
        LRU(job);
        for(int i=0;i<n;i++){
            cout << arr[i] <<" ";
        }
        cout <<"\n";
    }
}