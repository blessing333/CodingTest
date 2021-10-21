#include<bits/stdc++.h>
using namespace std;
int n,t;
bool answer[100001];
int check[100001];
int board[100001];
int cnt = 0;
void func(int next){
    if(answer[next] || check[next] == -1) return;

    if(check[next] == 0) check[next] = 1;
    else if(check[next] == 1){
        answer[next] = true;
        cnt++;
    }
    
    func(board[next]);
    check[next] = -1;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=1;i<=n;i++) cin >> board[i];
        cnt = 0;
        for(int i=1;i<=n;i++){
            if(check[i] == 0) func(i);
        }       
        cout << n-cnt <<"\n";
        for(int i=1;i<=n;i++){
            check[i] = 0;
            answer[i] = 0;
        }
    }
    
}