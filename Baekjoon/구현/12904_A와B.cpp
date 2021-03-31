#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    string t;
    cin >> s >>t;
    int result=0;
    while(true){
        if(t.size() == s.size()){
            if(t == s){
               result = 1;
            }
            break;
        }
        else{
            if(t[t.size()-1] == 'A'){
                t.pop_back();
            }
            else{
                t.pop_back();
                reverse(t.begin(),t.end());
            }
        }
    }
    cout << result;
}