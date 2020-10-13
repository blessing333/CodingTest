#include<bits/stdc++.h>
using namespace std;
int n,cnt;
vector<int> v;
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        int a; cin >> a; v.push_back(a);
    }

    for(int i=0;i<n-1;i++){
        bool flag=false;
        int cur=v[i];
        for(int j=i+1;j<n;j++){
            if(cur<=v[j]){
                flag=true;
                break;
            }
        }
        if(!flag){
            cnt++;
        }
    }
    cout << cnt;
}