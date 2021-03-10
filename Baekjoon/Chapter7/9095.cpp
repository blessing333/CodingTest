#include<bits/stdc++.h>
using namespace std;
int dp[15];
int main(){
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    dp[4] = 7;
    
    int tc;
    cin >> tc;
    
    for(int j=0;j<tc;j++){
        int n; cin >> n;
        for(int i=5;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        cout << dp[n];
    } 
}