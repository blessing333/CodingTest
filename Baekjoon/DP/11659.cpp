#include<bits/stdc++.h>
using namespace std;
int num[100005];
int s[100005];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m;
    s[0] = 0;
    cin >> n >> m;

    for(int i=1;i<=n;i++){
        cin >> num[i];
        s[i]=s[i-1] + num[i];
    }
    
    for(int i=1;i<=m;i++){
        int a,b;
        cin >> a >> b;
        cout << s[b]-s[a-1] << "\n";
    }
}