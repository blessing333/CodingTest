#include<bits/stdc++.h>
using namespace std;
bool notebook[105][105];
bool sticker[10][10];
int n,m,k,r,c,cnt;
/*
    스티커를 돌리는 함수
*/
void rotate(){
    bool tmp[10][10];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            tmp[i][j]=sticker[i][j];
        }
    }

    for(int i=0;i<c;i++){
        for(int j=0;j<r;j++){
            sticker[i][j]=tmp[r-1-j][i];
        }
    }

    swap(r,c);
}
/*  
    x,y를 입력받아 스티커를 붙히는 함수
    스티커를 붙히는데 성공하면 true, 아니면 false 리턴
*/
bool post(int x,int y){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(notebook[x+i][y+j]==1 && sticker[i][j]==1){
                return false;
            }
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(sticker[i][j])
                notebook[x+i][y+j]=1;
        }
    }
    return true;
}
int main(){
    cin >> n >> m >> k;
    while(k--){
        cin >> r >> c;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cin >> sticker[i][j];
            }
        }

        for(int rot=0;rot<4;rot++){
            bool isSuccess=false;
            for(int x=0;x<=n-r;x++){
                if(isSuccess)break;
                for(int y=0;y<=m-c;y++){
                    if(post(x,y)){
                        isSuccess=true;
                        break;
                    }
                }
            }
            if(isSuccess)break;
            rotate();
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(notebook[i][j]) cnt++;
        }
    }
    cout << cnt;
}