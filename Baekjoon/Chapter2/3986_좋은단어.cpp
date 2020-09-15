#include<bits/stdc++.h>
using namespace std;
int n,cnt;
string str;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++){
        stack<char> s;
        cin >> str;
        for(int i=0;i<str.size();i++){
            if(!s.empty()&&s.top()==str[i]){
                s.pop();
            }
            else
                s.push(str[i]);
        }

        if(s.empty())
            cnt++;
    }
    cout << cnt;
}