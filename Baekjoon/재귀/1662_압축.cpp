#include<bits/stdc++.h>
using namespace std;
string str;
bool check[50];
long long unzip(int n){
    long long ret = 0;
    
    for(int i= n;i<str.size();i++){
        if(str[i] == '(' && !check[i]){
            check[i] = true;
            long long prefix = str[i-1] -'0';
            ret--;
            ret += prefix * unzip(i+1);
        }
        else if(str[i] ==')' && !check[i]){
            check[i] = true;
            return ret;
        }
        else if(!check[i]){
            check[i] = true;
            ret++;
        }
    }
    return  ret;
}
int main(){
    cin >> str;
    cout << unzip(0);
}