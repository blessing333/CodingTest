#include<bits/stdc++.h>
using namespace std;
int r,c,m;
int curPos = -1;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
int counterDir[] = {1,0,3,2};
int answer = 0;
struct Shark{
    int x;
    int y;
    int w;
    int d;
    int s;
    
    bool operator> (const Shark &a) const{
        return w > a.w;
    }
    
    Shark(int row,int col,int speed,int dir,int weight){
        x=row;
        y=col;
        w=weight;
        d=dir;
        s=speed;
    }
};
vector<Shark> board[100][100];

void catchShark(){
    for(int i=0;i<r;i++){
        if(board[i][curPos].size() > 0){
            answer+=board[i][curPos][0].w;
            board[i][curPos].clear();
            return;
        }
    }
}

void sharkMove(){
    vector<Shark> tmp[100][100];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(board[i][j].size() > 0){
                Shark shark = board[i][j][0];
                int nx,ny;
                int iter;
                if(shark.d == 0 || shark.d == 1) iter = shark.s %(2*r-2);
                else iter = iter = shark.s %(2*c-2);
                for(int k=0;k<iter;k++){ //스피드 만큼 이동
                    nx = shark.x + dx[shark.d];
                    ny = shark.y + dy[shark.d];
                    if(nx < 0 || nx >= r || ny< 0 || ny>=c ){
                        if(nx < 0 ) nx+=2;
                        else if(nx>= r) nx-=2;
                        else if(ny<0) ny+=2;
                        else if(ny>=c) ny-=2;
                        shark.d = counterDir[shark.d];
                    }
                    shark.x=nx;
                    shark.y=ny;
                }
                tmp[shark.x][shark.y].push_back(shark);
            }
        }
    }
    
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(tmp[i][j].size() > 1){ //2마리 이상이면
                sort(tmp[i][j].begin(),tmp[i][j].end(),greater());
                Shark shark = tmp[i][j][0];
                tmp[i][j].clear();
                tmp[i][j].push_back(shark);
            }
        }
    }

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            board[i][j] = tmp[i][j];
        }
    }
}

int main(){
    cin >> r >> c >> m;
    for(int i=0;i<m;i++){
        int a,b,k,d,e,f;
        cin >> a >> b >> k >> d >> e;
        a--; b--; d--;
        board[a][b].push_back(Shark(a,b,k,d,e));
    }

    while(curPos<c-1){
    //while(curPos<0){
        curPos++; //한칸 이동
        catchShark(); // 상어 노획
        sharkMove(); //상어 이동
    }

    // cout << "\n";
    // for(int i=0;i<r;i++){
    //     for(int j=0;j<c;j++){
    //         cout << board[i][j].size() <<" ";
    //     }
    //     cout << "\n";
    // }

    cout << answer;
}