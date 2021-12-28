#include<bits/stdc++.h>
using namespace std;
int n,k;
int board[10][10];
//int arr[3][20];
vector<vector<int>> arr(3);
int main(){
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        arr[0].push_back(i);
        for(int j=1;j<=n;j++){
            cin >> board[i][j];
        }
    }
    for(int i=1;i<3;i++){
        for(int j=0;j<20;j++){
            int a;
            cin >> a;
            arr[i].push_back(a);
        }
    }
    bool done = false;
    
    do{
        // cout << "permu: { ";
        // for(auto it : arr[0]){
        //     cout << it << " ";
        // }
        // cout <<"} \n";

        int idx[3]={0,0,0};
        int player = 0;
        int next = 1;
        int cnt[3] = {0,0,0};
        bool over = false;
        int turn = 20;
        
        while(turn--){
            if(player > next) swap(player,next);
            for(int i=0;i<3;i++){
                if(cnt[i] >= k){
                    if(i == 0){
                        done=true;
                        // cout << "winner : " << i <<"\n";
                        break;
                    }
                    // cout << "winner : " << i <<"\n";
                    over = true;
                    break;
                }
            }
            if(done) break;
            if(over) break;
            if(idx[0] >= n) break;

            //가위 바위보 시작
            if(board[ arr[player][idx[player]] ] [arr[next][idx[next]]] == 2){ //승리
                idx[player]++;
                idx[next]++;
                cnt[player]++;
                next = 3-player-next;
            }
            else{ // next 승리
                idx[player]++;
                idx[next]++;
                cnt[next]++;
                player = 3-next-player;
            }
            
        }
        if(done) break;
    }while(next_permutation(arr[0].begin(),arr[0].end()));
    if(done) cout << 1;
    else cout << 0;
}