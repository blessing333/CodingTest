#include<bits/stdc++.h>
using namespace std;
int n;
vector<string> v;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n;
    int six=666;
    while(1) {
        string str=to_string(six++);
        
        if(str.find("666")!=-1)
            v.push_back(str);
        if(v.size()==n) break;
    }
    cout<<v[n-1];
}