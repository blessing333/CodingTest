#include<bits/stdc++.h>
using namespace std;
int team1[]={0,0,0,0,0,1,1,1,1,2,2,2,3,3,4};
int team2[]={1,2,3,4,5,2,3,4,5,3,4,5,4,5,5};
int board[4][6][3];
int result[6][3];
bool ret[4];

void combi(int round){ //round번째 경기를 진행하는 함수
    if(round==15){ // 15경기를 다 진행했다면 승패 예측 비교   
        for(int i=0;i<4;i++){
            if(ret[i])continue;
            bool flag=false;
            for(int j=0;j<6;j++){
                for(int k=0;k<3;k++){
                    if(board[i][j][k]!=result[j][k]){
                        flag=true;
                        break;
                    }
                }
                if(flag) break;
            }
            if(flag)continue;
            ret[i]=1;
            //return;
        }
        return;
    }

    int t1=team1[round];
    int t2=team2[round];

    //1팀이 이기고 2팀이 지는경우
    result[t1][0]++;
    result[t2][2]++;
    combi(round+1);
    result[t1][0]--;
    result[t2][2]--;

    //비기는 경우
    result[t1][1]++;
    result[t2][1]++;
    combi(round+1);
    result[t1][1]--;
    result[t2][1]--;
    
    // 1팀이 지고 2팀이 이기는 경우
    result[t1][2]++;
    result[t2][0]++;
    combi(round+1);
    result[t1][2]--;
    result[t2][0]--;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for(int i=0;i<4;i++){
        for(int j=0;j<6;j++){
            for(int k=0;k<3;k++){
                cin >> board[i][j][k];
            }
        }
    }

    combi(0);
    for(int i=0;i<4;i++){
        cout << ret[i] <<" ";
    }
}