#include<bits/stdc++.h>
using namespace std;
int n,k,arr[2001],cnt,total;

void job(int idx){
    if(arr[idx]>0){
        arr[idx]--;
        cnt++;        
    }    
}

int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
        total+=arr[i];
    }
    cin >> k;
    if(total<=k){
        cout << -1;
        return 0;
    }

    int idx=0;
    while(cnt<k){
        idx++;
        if(idx>n) idx=1;
        job(idx);
        // for(int i=1;i<=n;i++){
        //     cout << arr[i] << "  ";
        // }
        // cout << "   cnt : "<<cnt<<"\n";
    }

    while(1){
        idx++;
        if(idx>n) idx=1;
        if(arr[idx]>0){
            cout << idx;
            break;
        }
    }
    
}