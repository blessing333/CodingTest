/*
    1. 스트링으로 입력을 받는다.
    2. 받은 문자열의 반복자로 아스키 범위를 검사하여 다른 배열에 넣는다.
    3. 약수를 구한다.
*/

#include<bits/stdc++.h>
using namespace std;
string str;
string str2="";
int cnt;
int main(){
    getline(cin,str);
    for(auto it : str){
        if(it <= '9' && it >='0')
            str2+=it;
    }
    int n=stoi(str2);
    for(int i=1;i<=n;i++){
        if(28%i==0)
            cnt++;
    }
    cout << n << "\n";
    cout << cnt;
}