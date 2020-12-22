#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
    int arr[26];
    fill_n(arr,26,-1);
    cin >> s;
    for(int i=0;i<s.size();i++){
        char it=s[i];
        if(arr[it-'a']==-1)
            arr[it-'a']=i;
    }

    for(int i=0;i<26;i++){
        cout << arr[i] <<" ";
    }
}