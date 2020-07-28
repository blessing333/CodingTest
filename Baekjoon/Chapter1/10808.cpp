#include<bits/stdc++.h>
using namespace std;

string s;
int main(){
    cin>>s;
    for(char c='a';c<='z';c++){
        int cnt=0;
        for(char c2 :s){
            if(c==c2){
             cnt++;
            }
        }
        printf("%d " ,cnt);
    }
}