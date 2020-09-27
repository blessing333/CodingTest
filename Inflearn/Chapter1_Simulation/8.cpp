/*
    목표 : 올바른 괄호 쌍 판별
    1. 괄호 문자열을 입력 받는다.
    2. 문자열의 각 문자에 대하여 반복
        - 첫번째 괄호를 스택에 넣는다
        - 다음 괄호를 조회하여 스택 꼭대기의 괄호와 쌍이 맞는다면 스택에서 팝한다.
        - 아니라면 스택에 넣는다.
        - 모든 괄호를 조회한 뒤 스택이 비어있지 않다면 no를 출력한다.
*/

#include<bits/stdc++.h>
using namespace std;
stack<char> stk;
string str;

int main(){
    getline(cin,str);
    for(int i=0;i<str.size();i++){
        char it=str[i];
        char top;
        if(stk.empty()){
            stk.push(it);
            continue;
        }

        top=stk.top();
        if(top=='('){
            if(it==')')
                stk.pop();
            else
                stk.push(it);
        }
        // else{
        //     if(it=='(')
        //         stk.pop();
        //     else
        //         stk.push(it);
        // }   
    }
       if(stk.empty()) cout << "YES";
       else
        cout << "NO";
}