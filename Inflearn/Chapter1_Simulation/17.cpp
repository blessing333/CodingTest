#include<bits/stdc++.h>
using namespace std;
int tc,n,answer;
int main(){
    cin >> tc;
    for(int i=0;i<tc;i++){
        cin >> n >> answer;
        int solution=0;
        for(int j=1;j<=n;j++){
            solution+=j;
        }
        if(solution==answer)
            cout << "YES"<<"\n";
        else cout << "NO"<<"\n";
    }
}