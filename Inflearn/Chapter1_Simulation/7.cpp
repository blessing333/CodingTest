/*
    목표 : 영어 단어 복원
    1. 손상된 영어 문장 입력받기
    2. 해당 문자열의 모든 문자에 대하여 반복
        - 대문자일 경우, 소문자로 변환
        - 공백일 경우 제거
    3. 복원된 문자열 출력
*/  

#include<bits/stdc++.h>
using namespace std;
vector<char> v;
int main(){
    string str;
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);
    getline(cin,str);
    for(char it : str){
        if(it==' ') continue;
        if(it<='Z' && it>='A'){
            it=tolower(it);
        }
        v.push_back(it);
    }
    for(char it : v){
        cout<< it;
    }
}