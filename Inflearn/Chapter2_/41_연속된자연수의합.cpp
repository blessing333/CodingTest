#include<bits/stdc++.h>
using namespace std;
int main(){
    int a=1,sum=0,div=0,n,c,cnt=1;
    cin >> n;
    c=n;
    do{
        n-=a;
        if(a==1){
            a++;
            cnt++;
            continue;
        }
        if(n%cnt==0){
            div=n/cnt;
            cout << 1+div;
            for(int i=2;i<=cnt;i++){
                cout << " + " << i+ div;
            }
            cout << " = " << c << "\n";
            
        }
        cnt++;a++;
    }while(n>0);
    
    
}