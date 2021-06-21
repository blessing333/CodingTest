#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct Fireball{
    int r;
    int c;
    int w;
    int s;
    int d;
    Fireball(int row,int col, int mass,int speed, int dir){
        r = row;
        c =col;
        w=mass;
        s=speed;
        d=dir;
    }
};

int dx[] = {-1,-1,0,1,1,1,0,-1};
int dy[] = {0,1,1,1,0,-1,-1,-1};

vector<Fireball> board[50][50];
int main(){
    cin >> n >> m >> k;
    for(int i=0;i<m;i++){
        int a,b,c,d,e;
        cin >> a >> b >> c  >> d >> e;
        a--; b--;
        board[a][b].push_back(Fireball(a,b,c,d,e));
    }
    while(k-- > 0){
        vector<Fireball> tmp[50][50];
        for(int i=0;i<n;i++){
            for(int j =0;j<n;j++){
                if(board[i][j].size()>0){ // 파이어볼이 있으면 이동
                    for(auto it : board[i][j]){ // 모든 파이어볼에 대하여
                        int nx = it.r;
                        int ny = it.c;
                        for(int k=0;k<it.s;k++){
                            nx = nx+dx[it.d];
                            ny = ny+dy[it.d];
                            if(nx < 0) nx=n-1;
                            if(nx >= n) nx =0;
                            if(ny < 0) ny=n-1;
                            if(ny >= n) ny =0;
                        }
                        tmp[nx][ny].push_back(Fireball(nx,ny,it.w,it.s,it.d));
                    }
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j =0;j<n;j++){
                if(tmp[i][j].size()>=2){ // 파이어볼이 2개있으면
                    int sz = tmp[i][j].size();
                    bool even= false;
                    bool odd = false;
                    int mass=0;
                    int speed=0;
                    for(auto it : tmp[i][j]){ // 모든 파이어볼에 대하여
                        speed += it.s;
                        mass += it.w;
                        if(it.d %2 ==0) even = true;
                        else odd = true;
                    }
                    tmp[i][j].clear();
                    int curMass = mass/5;
                    if(curMass == 0) continue;
                    int curSpeed = speed / sz;
                    int curDir;

                    if(even != odd) curDir = 0;
                    else curDir=1;
                    
                    for(int k=0;k<4;k++){
                        tmp[i][j].push_back(Fireball(i,j,curMass,curSpeed,curDir));
                        curDir+=2;
                    }
                }
            }
        }
        
        
        for(int i=0;i<n;i++){ //복사
            for(int j=0;j<n;j++){
                board[i][j] = tmp[i][j];
            }
        }

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout << tmp[i][j].size() <<" ";
        //     }
        //     cout<<"\n";
        // }
        // cout <<"\n";
    }


    int answer = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j].size() > 0){
                for(auto it : board[i][j]) answer+=it.w;
            }
        }
    }
    cout << answer;
}