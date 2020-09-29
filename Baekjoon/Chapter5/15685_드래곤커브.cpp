#include<bits/stdc++.h>
using namespace std;
int dx[]={0,-1,0,1};
int dy[]={1,0,-1,0};
int board[105][105];
int visit[105][105];
int n;
struct Dragon{
    int x;
    int y;
    int dir;
    int z; //세대
};
vector<Dragon> dragon;
vector<pair<int,int>> v;

void makeDragon(){ //시작 좌표,방향,세대를 받아 드래곤 커브르 만드는 험수
    for(auto it : dragon){
        vector<int> candi;
        pair<int,int> cur ={it.x,it.y};
        board[it.x][it.y]=1;
        candi.push_back(it.dir);

        for(int i=0;i<it.z;i++){
            int size=candi.size();
            for(int j=size-1;j>-1;j--){
                candi.push_back((candi[j]+1)%4);
            }
        }
        
        for(int i=0;i<candi.size();i++){
            int dir=candi[i];
            int nx=cur.first+dx[dir];
            int ny=cur.second+dy[dir];
            board[nx][ny]=1;
            cur={nx,ny};
        }
    }
}
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        Dragon dra;
        int x,y,dir,z;
        cin >> y >> x >> dir >> z;
        dra.x=x; dra.y=y; dra.dir=dir; dra.z=z;
        dragon.push_back(dra);
    }

    makeDragon();

    int cnt=0;
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
         if (board[i][j] && board[i][j + 1] && board[i + 1][j] && board[i + 1][j + 1]) {
                cnt++;
            }   
        }
    }
    cout << cnt;

}

