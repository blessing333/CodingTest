#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    while(true){
        string str;
        getline(cin,str);
        stack<char> s;
        s.push('d');

        if(str==".")
            break;

        for(char c : str){
            if(c=='[' || c=='('){
                s.push(c);
            }
            else if(c==']'){
                if(s.top()=='['){
                    s.pop();
                }
                else
                    s.push(c);
            }
            else if(c==')'){
                if(s.top()=='('){
                    s.pop();
                }
                else
                    s.push(c);
            }
        }
        
        if(s.size()>1){
            cout << "no\n";
        }
        else
            cout <<"yes\n";

    }
}