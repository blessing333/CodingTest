#include<bits/stdc++.h>
using namespace std;
string converter(int cnt){
    string str="";
    int m=cnt/60;
    int s=cnt%60;
    if(m<10){
        str+="0";
    }
    str+=to_string(m);
    str+=":";
    if(s<10){
        str+="0";
    }
    str+=to_string(s);
    return str;
}
int n,arr1[2880],arr2[2880],cnt1,cnt2;
string str;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;  cin.ignore();
    for(int i=0;i<n;i++){
        getline(cin,str);
        int t=atoi(str.substr(0,1).c_str());
        int m=atoi(str.substr(2,4).c_str());
        int s=atoi(str.substr(5).c_str());
        
        for(int j=m*60+s;j<2880;j++){
            if(t==1){
                arr1[j]++;
            }
            else{
                arr2[j]++;
            }
        }
    }
    for(int j=0;j<2880;j++){
            if(arr1[j]>arr2[j])
                cnt1++;
            else if(arr1[j]<arr2[j])
                cnt2++;
        }
    cout << converter(cnt1)<<"\n";
    cout << converter(cnt2);
}