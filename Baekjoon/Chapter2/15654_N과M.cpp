
#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> v1, v2;
bool check[10];

void permu(){
    if(v2.size()==m){
        for(auto it:v2)
            cout<<v1[it]<<" ";
        cout << "\n";
        return;
    }

    for(int i=0;i<n;i++){
        if(check[i])
            continue;
        check[i]=true;
        v2.push_back(i);
        permu();
        check[i]=false;
        v2.pop_back();
    }

}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        int k;
        cin >> k;
        v1.push_back(k);
    }
    sort(v1.begin(),v1.end());
    permu();
    
    
}