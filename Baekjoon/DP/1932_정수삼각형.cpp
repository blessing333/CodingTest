#include<bits/stdc++.h>
using namespace std;
int n;
int dp[505][505];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    vector<vector<int>> v(n);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            int a; cin >> a;
            v[i].push_back(a);
        }
    }
    dp[0][0] = v[0][0];

    for(int i=1;i<n;i++){
        for(int j=0;j<=i;j++){
            if(j == 0) dp[i][j] = dp[i-1][j] + v[i][j];
            else if(j == i) dp[i][j] = dp[i-1][j-1] + v[i][j];
            else dp[i][j] = max(dp[i-1][j-1] + v[i][j], dp[i-1][j] + v[i][j]);
        }
    }
    
    int answer = 0;
    for(int j=0;j<n;j++){
        answer = max(dp[n-1][j],answer);
    }
    cout << answer;
   
}