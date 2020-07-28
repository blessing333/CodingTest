#include<bits/stdc++.h>
using namespace std;

// 일단 문자열로 받고 아스키코드 65~90 사이면 이름임
int n,m;
string name;
string s;
map<int,string> d;
map<string,int>d2;
int main(){
    cout << "first line \n";
    cin >> n >> m; 
    cout << "second line \n";
    for(int i=0;i<n;i++){
        cin >> name;
        cout << name+"";
        d.insert(make_pair(i,name));
        d2.insert(make_pair(name,i));
        cout<<d[1];
    }
    cout << "end input \n";

    for(int i=0;i<m;i++){
        cin>>s;

        if(s.at(0)>=65&&s.at(0)<=90){
            printf("%d\n",d2.find(s));
        }
        else
        {
            int a=stoi(s);
            printf("%d\n",a);
            printf("%s\n",d.find(a));
        }
        
    }

    
}