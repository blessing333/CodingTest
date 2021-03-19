#include<bits/stdc++.h>
using namespace std;
int n,answer=0;
int board[20][20];
void moveBlock(int dir){
    bool checked[20][20];
    fill(&checked[0][0],&checked[0][0]+400,false);
    if(dir==0){
        //모든 컬럼에 대하여 반복
        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                if(board[j][i]!=0){
                    
                    //1.바로 위에 있는 블록이 0이 아닐때 까지 땡긴다.
                    int idx=j; //j : 현재 탐색중인 블록, idx :위에 있는 블록
                    while(idx-1 >= 0 && board[idx-1][i] == 0 ){
                        board[idx-1][i] = board[idx][i];
                        board[idx][i]=0;
                        idx--;
                    }
                    //2. 같고 합쳐진적이 없으면 합친다
                    if(idx-1 >= 0 && board[idx-1][i] == board[idx][i] && !checked[idx-1][i]){
                        board[idx-1][i] +=board[idx][i];
                        board[idx][i] = 0;
                        checked[idx-1][i] = true;
                    }
                    //3. 다르면 아무것도 안한다.
                }
            }
        }       
    }
    else if(dir==1){
        //모든 컬럼에 대하여 반복
        for(int i=0;i<n;i++){
            for(int j=n-2;j>=0;j--){
                if(board[i][j]!=0){
                    //1.바로 아래 있는 블록이 0이 아닐때 까지 땡긴다.
                    int idx=j; //j : 현재 탐색중인 블록, idx :오른쪽에 있는 블록
                    while(idx+1 < n && board[i][idx+1] == 0 ){
                        board[i][idx+1] = board[i][idx];
                        board[i][idx]=0;
                        idx++;
                    }
                    //2. 같고 합쳐진적이 없으면 합친다
                    if(idx+1 < n && board[i][idx+1] == board[i][idx] && !checked[i][idx+1]){
                        board[i][idx+1] +=board[i][idx];
                        board[i][idx] = 0;
                        checked[i][idx+1] = true;
                    }
                    //3. 다르면 아무것도 안한다.
                }
            }
        }       
    }
     else if(dir==2){
        //모든 컬럼에 대하여 반복
        for(int i=0;i<n;i++){
            for(int j=n-2;j>=0;j--){
                if(board[j][i]!=0){
                    //1.바로 아래 있는 블록이 0이 아닐때 까지 땡긴다.
                    int idx=j; //j : 현재 탐색중인 블록, idx :아래 있는 블록
                    while(idx+1 < n && board[idx+1][i] == 0 ){
                        board[idx+1][i] = board[idx][i];
                        board[idx][i]=0;
                        idx++;
                    }
                    //2. 같고 합쳐진적이 없으면 합친다
                    if(idx+1 < n && board[idx+1][i] == board[idx][i] && !checked[idx+1][i]){
                        board[idx+1][i] +=board[idx][i];
                        board[idx][i] = 0;
                        checked[idx+1][i] = true;
                    }
                    //3. 다르면 아무것도 안한다.
                }
            }
        }       
    }
    else if(dir==3){
        //모든 컬럼에 대하여 반복
        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                if(board[i][j]!=0){
                    //1.바로 아래 있는 블록이 0이 아닐때 까지 땡긴다.
                    int idx=j; //j : 현재 탐색중인 블록, idx :오른쪽에 있는 블록
                    while(idx-1 >= 0 && board[i][idx-1] == 0 ){
                        board[i][idx-1] = board[i][idx];
                        board[i][idx]=0;
                        idx--;
                    }
                    //2. 같고 합쳐진적이 없으면 합친다
                    if(idx-1 >= 0 && board[i][idx-1] == board[i][idx] && !checked[i][idx-1]){
                        board[i][idx-1] +=board[i][idx];
                        board[i][idx] = 0;
                        checked[i][idx-1] = true;
                    }
                    //3. 다르면 아무것도 안한다.
                }
            }
        }       
    }
    
    // cout << "\n";
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout << board[i][j]<<" ";
    //     }
    //     cout << "\n";
    // }
}

void dfs(int level,int cur,int dir){
    if(cur == level){
        //가장 큰 블럭 찾아서 갱신
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                answer=max(answer,board[i][j]);
            }
        }
        return;
    }
    else{
        for(int i=0;i<4;i++){
            int tmp[20][20];
            copy(&board[0][0],&board[0][0]+400,&tmp[0][0]);
            moveBlock(i);
            dfs(level,cur+1,i);
            copy(&tmp[0][0],&tmp[0][0]+400,&board[0][0]);
        }
    }
    
}
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> board[i][j];
        }
    }
    
    for(int i=1;i<=5;i++){
        dfs(i,0,0);
    }
    
    
    cout << answer;
}