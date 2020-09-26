#include<bits/stdc++.h>
using namespace std;
string str;
char a;
int main(){
     ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
     getline(cin,str);
    int year=str[7]=='1' || str[7]=='2' ? 1900+(str[0]-'0')*10+(str[1]-'0') : 2000+(str[0]-'0')*10+(str[1]-0);
    cout << year << "\n";
    int age=2019-year+1;
    char gender= str[7]=='1' || str[7]=='3' ? 'M' : 'W';
    cout << age << " " << gender;    
}