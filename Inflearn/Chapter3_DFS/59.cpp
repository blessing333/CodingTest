#include<bits/stdc++.h>
using namespace std;
int n;
bool check[11];
void func(int level){
    if(level==n+1){
        for(int i=1;i<=n;i++){
            if(check[i])
                cout << i <<" ";
        }
        cout << "\n";
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
    func(1);

}