#include<bits/stdc++.h>
using namespace std;
int n,arr[11];
bool check[11],flag;
void func(int level){
    if(level==n+1){
        int a=0;
        int b=0;
        for(int i=1;i<=n;i++){
            if(check[i])
                a+=arr[i];
            else
                b+=arr[i];
        }
        if(a==b){
            flag=true;
        }
    }

    else{
        check[level]=true;
        func(level+1);
        check[level]=false;
        func(level+1);

    }
}
int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    func(1);
    if(flag)
        cout << "YES";
    else
        cout << "NO";
}
