#include<bits/stdc++.h>
using namespace std;
int n,m,sum;
int main(){
    cin >> n >> m;
    
    for(int i=n;i<=m;i++){
        cout << i <<" ";
        sum+=i;
        if(i==m){
            break;
        }
        cout << "+ ";
    }
    cout <<"= "<< sum;
}