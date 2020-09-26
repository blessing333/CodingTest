/*
    1. n과 k를 입력 받는다.
    2. 
*/

#include<bits/stdc++.h>
using namespace std;
int n,k,result,maximum=-1;
bool check[26];
string str[50];
vector<int> v;
void condition(){ //읽을 수 있는 단어의 수를 체크하는 함수
    int cnt=0;
    for(int i=0;i<n;i++){
        bool flag=true;
        for(auto it : str[i]){
            if(check[it-'a']==false){
                flag=false;
                break;
            }
        }
        if(flag)
            cnt++;
    }
    maximum=max(maximum,cnt);
}

void combi(int here){
    if(v.size()==k){
        condition();
        return;
    }
    for(int i=here+1;i<26;i++){
        if(check[i])continue;
        check[i]=true;
        v.push_back(i);
        combi(i);
        check[i]=false;
        v.pop_back();
    }
}

int main(){
    cin >> n >> k;
    if(k<5)
        cout << 0;
    
    else{
        cin.ignore();
        for(int i=0;i<n;i++){
            getline(cin,str[i]);
        }
        check[0]=true;
        check[2]=true;
        check['i'-'a']=true;
        check['t'-'a']=true;
        check['n'-'a']=true;
        k-=5;
        combi(-1);
        cout << maximum;
    }
}