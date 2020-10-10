#include<bits/stdc++.h>
using namespace std;
string s,s2;
int arr[52], arr2[52];
int main(){
    cin >> s;
    cin >> s2;

    for(auto it : s){
        if(it>='a' && it<='z'){
            arr[it-'a']++;
        }
        else{
            arr[it-'A'+27]++;
        }

    }

    for(auto it : s2){
        if(it>='a' && it<='z'){
            arr2[it-'a']++;
        }
        else{
            arr2[it-'A'+27]++;
        }
    }
    int flag=true;
    for(int i=0;i<52;i++){
        if(arr[i]!=arr2[i])
            flag=false;
    }
    if(flag)
         cout << "YES";
     else
         cout<< "NO";
}