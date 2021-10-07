#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    vector<int> v,v2,result;

    for(int i=0;i<n;i++){
        int a; cin >> a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());

    for(int j=0;j<m;j++){
        int a; cin >> a;
        v2.push_back(a);
    }
    sort(v2.begin(),v2.end());

    //set_difference(v.begin(),v.end(),v2.begin(),v2.end(),inserter(result,result.begin()));
    for(auto it : v){
        if(!binary_search(v2.begin(),v2.end(),it)) result.push_back(it);
    }
    cout << result.size() <<"\n";
    for(auto it : result) cout << it << " ";
}