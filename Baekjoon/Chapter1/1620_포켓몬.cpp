#include<bits/stdc++.h>
using namespace std;

int n,m;
char name[21];

string arr[100005];
map<string,int>mp;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m; 
    for(int i=0;i<n;i++){ 
        cin >> name;
        arr[i]=name;
        mp.insert(pair<string,int>(name,i));
    }

    for(int i=0;i<m;i++){ 
        cin>>name;
        if(isdigit(name[0])){
            cout << arr[atoi(name)-1] << "\n";
        }
        else
        {
           cout << mp[name]+1 << "\n";
        }
    }
}