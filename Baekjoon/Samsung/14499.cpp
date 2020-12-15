#include<bits/stdc++.h>
using namespace std;
int n,m,start_x,start_y,k,board[20][20],arr[1000];
int dx[]={0,0,-1,1},dy[]={1,-1,0,0},dice[6];

void rotateDice(int dir){
    int before[6];
    copy(dice,dice+6,before);
    if(dir==0){
        dice[0]=before[2];
        dice[1]=before[3];
        dice[2]=before[1];
        dice[3]=before[0];
    }
    else if(dir==1){
        dice[0]=before[3];
        dice[1]=before[2];
        dice[2]=before[0];
        dice[3]=before[1];
    }
    else if(dir==2){
        dice[2]=before[4];
        dice[3]=before[5];
        dice[4]=before[3];
        dice[5]=before[2];
    }
    else if(dir==3){
        dice[2]=before[5];
        dice[3]=before[4];
        dice[4]=before[2];
        dice[5]=before[3];
    }
}
int main(){
    cin >> n >> m >> start_x >> start_y >> k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int a; cin >> a;
            board[i][j]=a;
        }
    }
    for(int i=0;i<k;i++){
        cin >> arr[i];
        arr[i]--;
    }
    
    for(int i=0;i<k;i++){
        int dir=arr[i];
        int nx=start_x+dx[dir];
        int ny=start_y+dy[dir];
        if(nx>=n || nx < 0 || ny>=m ||ny<0) continue;
        rotateDice(dir);
        if(board[nx][ny]==0){
            board[nx][ny]=dice[3];
        }
        else{
            dice[3]=board[nx][ny];
            board[nx][ny]=0;
        }
        cout<<dice[2]<<"\n";
        start_x=nx; start_y=ny;
    }
}