#include<bits/stdc++.h>
using namespace std;
int n,m;
char board[11][11];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int answer = 11;

void dfs(int level,int rx, int ry, int bx, int by){
    if(level > answer) return;
    else if(level > 10) return;
    else{
        for(int i=0;i<4;i++){
            bool samePos = false;
            bool redOut = false;
            int redX = rx;
            int redY = ry;
            int redDist = 0;

            bool blueOut = false;
            int blueX = bx;
            int blueY = by;
            int blueDist = 0;

            while(true){
                redX += dx[i];
                redY += dy[i];
                if(board[redX][redY] == '#'){
                    redX -= dx[i];
                    redY -= dy[i];
                    break;
                }
                else if(board[redX][redY] == 'O'){
                    redOut = true;
                    break;
                }
                else if(board[redX][redY] == '.'){
                    redDist++;
                }
            }

            while(true){
                blueX += dx[i];
                blueY += dy[i];
                if(board[blueX][blueY] == '#'){
                    blueX -= dx[i];
                    blueY -= dy[i];
                    break;
                }
                else if(board[blueX][blueY] == 'O'){
                    blueOut = true;
                    break;
                }
                else if(board[blueX][blueY] == '.'){
                    blueDist++;
                }
            }

            if(blueOut) continue;
            if(blueOut && redOut) continue;

            if(blueX == redX && blueY == redY) samePos = true;
            if(redOut && !blueOut && !samePos){
                answer = min(answer,level);
                return;
            }

            if(samePos){
                if(redDist > blueDist){
                    redX -= dx[i];
                    redY -= dy[i];
                }
                else{
                    blueX -= dx[i];
                    blueY -= dy[i];
                }
            }
           dfs(level+1,redX,redY,blueX,blueY);
        }
    }
}

int main(){
    cin >> n >> m;
    int rx,ry,bx,by;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
            if(board[i][j] == 'B'){
                bx = i;
                by = j;
                board[i][j] = '.';
            }
            else if(board[i][j] == 'R'){
                rx = i;
                ry = j;
                board[i][j] = '.';
            }
        }
    }

    dfs(1,rx,ry,bx,by);

    answer = answer == 11 ? -1 : answer;
    cout << answer;
    
}
