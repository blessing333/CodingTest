#include<bits/stdc++.h>
using namespace std;
vector<char> v;
int l,c;
bool checkCondition(string s){
    int zaum = 0;
    int moum = 0;
    for(auto it : s){
        if(it == 'a'|| it == 'e' || it == 'o' || it == 'u' ||it=='i'){
            moum++;
        }
        else
            zaum++;
    }
    if(zaum >= 2 && moum >= 1) return true;
    else return false;
}

void func(int level,string s){
    if(s.size() == l){
        if(checkCondition(s)){
            
            cout << s <<"\n";
        }
        return;
    }
    else{
        for(int i=level+1; i<v.size(); i++){
            s.push_back(v[i]);
            func(i,s);
            s.pop_back();
        }
    }
    
}

int main(){
    
    cin >> l >> c;    
    for(int i=0;i<c;i++){
        char a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    string s="";
    func(-1,s);
}