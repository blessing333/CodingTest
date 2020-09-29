#include<bits/stdc++.h>
using namespace std;
int dice[10], //주사위
board[50], // 지도
score[50], // 각 칸의 점수
turn[50], // 전환점
check[50], // 해당 칸에 말이 있는지 체크하는 변수
horse[4] // 말의 위치를 저장하는 변수
,maximum=-1,total=0;
; 
/*
    말을 주사위 눈금만큼 움직이는 함수
    1. 10번 움직이면 점수의 총합을 maximum에 저장한다
*/
void dfs(int sum,int cnt){ 
    if(cnt==10){
        maximum=max(maximum,sum);
        return;
    }

    for(int i=0;i<4;i++){
        int prev = horse[i]; //현재 위치
        int now=prev; // 이전 위치
        int move=dice[cnt];
        
        if(turn[now]>0){ //분기점이면 파란 화살표로 이동
            now=turn[now];
            move--;
        }
        while(move--){ //이동
            now=board[now];
        }

        if(now!=21 && check[now])continue;
        check[prev]=0;
        check[now]=1;
        horse[i]=now;
        dfs(sum+score[now],cnt+1);
        horse[i]=prev;
        check[prev]=1;
        check[now]=0;

    }  
}
int main(){
    ios_base::sync_with_stdio(0);cout.tie(NULL); cin.tie(NULL);
    for(int i=0;i<10;i++){
        cin >> dice[i];
    }
    
    // 지름길을 통하지 않고 돌아가는 경로의 점수표 index 1~20 0은 시작칸 21은 도착칸 
    for(int i=0;i<=20;i++){
        score[i]=i*2;
    }
    //10점에서 오른쪽으로 빠지는 루트
    score[22]=13;
    score[23]=16;
    score[24]=19;
    score[25]=25;

    //20점에서 올라가는 루트
    score[31] = 22;
	score[32] = 24;

    //30점에서 왼쪽으로 빠지는 루트
	score[28] = 28;
	score[29] = 27;
	score[30] = 26;
    
    //25점에서 올라가는 루트
	score[26] = 30;
	score[27] = 35;

    turn[5] = 22;
	turn[10] = 31;
	turn[15] = 28;
	turn[25] = 26;

    for(int i=0;i<=20;i++){
        board[i]=i+1;
    }
    board[21]=21;
    board[22]=23;
    board[23]=24;
    board[24]=25;

    board[31]=32;
    board[32]=25;

    board[28]=29;
    board[29]=30;
    board[30]=25;

    board[25]=26;
    board[26]=27;
    board[27]=20;
    dfs(0,0);
    cout << maximum;

}