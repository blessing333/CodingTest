#include<bits/stdc++.h>

using namespace std;

int n,m;
string s;
string s2;
map<string,int> mp;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++){
        int result=1;
        mp.clear();
        cin >> m ;
        for(int j=0;j<m;j++){
            cin >> s >> s2;
            if(mp.find(s2)==mp.end())
                mp.insert(make_pair(s2,1));
            else
                mp[s2]++;
        }

        for(auto it : mp){
        result*=(it.second+1);
    }
    cout << result-1 << "\n";
    }
}
