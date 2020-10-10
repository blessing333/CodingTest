/*
    1. 모든 문자가 짝수개 있는 경우
    2. 하나의 문자를 제외한 다른 문자들이 짝수인 경우
*/


#include<bits/stdc++.h>
using namespace std;
vector<char> v;
vector<char> v2;
string str;
int alpha[26],cnt,idx=-1,flag;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);cout.tie(NULL);
    getline(cin,str);
    for(char c : str){
        alpha[c-'A']++;
    }

    for(int i=0;i<26;i++){
        if(alpha[i]%2==1){
            cnt++;
            flag=1;
            if(cnt==2){
                cout<<"I'm Sorry Hansoo";
                return 0;
            }
            idx=i;
        }
    }

    for(int i=0;i<26;i++){
        char c;
        if(alpha[i] && alpha[i]%2==0){
            for(int j=0;j<alpha[i]/2;j++){
                c=i+'A';
                v.push_back(i+'A');
                cout << c;
            }
        }

        else if(alpha[i] && alpha[i]%2==1){
            for(int j=0;j<(alpha[i]-1)/2;j++){
                c=i+'A';
                v.push_back(i+'A');
                cout << c;
            }
        }
    }
    
    if(flag){
        char c;
        c=idx+'A';
        cout << c;
        
    }

    for(int i=(int)v.size()-1;i>=0;i--){
        cout <<v[i];
    }
}