#include<bits/stdc++.h>
using namespace std;

string s;
char s2[100];
int result=1;
int main(){
    cin>>s;
    int j=s.size()-1;
    for(int i=0;i<s.size();i++){
        s2[i]=s.at(j--);
        if(s.at(i)!=s2[i]){
            result=0;
            break;
        }
    }
    printf("%d",result);
        
}