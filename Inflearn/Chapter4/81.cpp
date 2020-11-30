#include<bits/stdc++.h>
using namespace std;
vector<int> candi,v;
int n,k,cnt;
bool check[16];
void permu(){
    if(candi.size()==k){
        for(auto it: candi){
            cout << it << " ";
        }
        cout << "\n";
        cnt++;
    }
    else{
        for(int i=0;i<v.size();i++){
            if(check[v[i]]) continue;
            check[v[i]]=true;
            candi.push_back(v[i]);
            permu();
            candi.pop_back();
            check[v[i]]=false;
        }
    }
}

int main(){
    cin >> n >> k;
    for(int i=0;i<n;i++){
        int a;  cin >> a;
        v.push_back(a);
    }
    permu();
    cout << cnt;
}