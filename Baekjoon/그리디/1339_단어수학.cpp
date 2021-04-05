#include<bits/stdc++.h>
using namespace std;
int n;
vector<string> v;
priority_queue<int> pq;
int alpha[26];

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        if(s.size() < 8){
            while(s.size() != 8) s = "x" + s;      
        }
        v.push_back(s);
    }
    for(auto it : v){
        int decimal = 1;
        for(int i=7;i>=0;i--){
            char c =it[i];
            if(c == 'x') break;
            alpha[c-'A']+=decimal;
            decimal*=10;
        }
    }
    for(int i=0;i<26;i++){
        if(alpha[i] > 0) pq.push(alpha[i]);
    }

    int answer = 0;
    int multifler=9;
    while(!pq.empty()){
        int a= pq.top(); pq.pop();
        answer = answer + a*multifler;
        multifler--;
    }
    cout << answer;
}
