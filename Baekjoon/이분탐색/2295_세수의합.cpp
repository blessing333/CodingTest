#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
vector<int> v2;
int main(){
    cin >> n;    
    for(int i=0;i<n;i++){
        int a; cin >> a;
        v.push_back(a);
    }
    
    sort(v.begin(),v.end());
    
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            v2.push_back(v[i]+v[j]);
        }
    }
    
    sort(v2.begin(),v2.end());
    
    bool flag = false;
    
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=i;j++){
            int target = v[i] - v[j];
            if(binary_search(v2.begin(),v2.end(),target)){
                cout << v[i];
                flag = true;
                break;
            }
        }
        if(flag) break;
    }
    
}