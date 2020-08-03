/*
    1.스택에 하나씩 넣어서 같은 알파벳이면 제거
*/
#include<bits/stdc++.h>
using namespace std;

int n;
int cnt;
string str;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++){
        stack<char> s;
        cin >> str;
        for(auto c: str){
            if(!s.empty() && s.top()==c)
                s.pop();
            else
                s.push(c);
        }
    if(s.empty())
            cnt++;
    
    }
    cout << cnt;
}