#include<bits/stdc++.h>
using namespace std;
int board[100][100];
int check[100][100];
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int a,b,n,m;
struct Info{
    int x;
    int y;
    int dir;
    Info(int a,int b,int c){
        x=a; y=b; dir=c;
    }
    Info(){}
};
map<int,Info> robotMap;

int moveRobot(int id,char order,int iter){
    //Info info = robotMap[id];
    for(int i= 0;i<iter;i++){
        if(order == 'L'){
            robotMap[id].dir-=1;
            if(robotMap[id].dir==-1) robotMap[id].dir=3;
        }
        else if(order =='R'){
            robotMap[id].dir+=1;
            if(robotMap[id].dir==4) robotMap[id].dir=0;
        }
        else{
            int nx = robotMap[id].x + dx[robotMap[id].dir];
            int ny = robotMap[id].y + dy[robotMap[id].dir];
            //cout << "\n"<<nx << ", " <<ny<<"\n";
            if(nx >= a || nx <0 || ny >=b || ny<0) return -1;
            if(check[nx][ny] > 0) return check[nx][ny];
            check[robotMap[id].x][robotMap[id].y] = 0;
            check[nx][ny] = id;
            robotMap[id].x=nx;
            robotMap[id].y=ny;
        }
        robotMap[id].dir = robotMap[id].dir % 4;
        //cout << robotMap[id].x <<" , "<<robotMap[id].y<<" , " << robotMap[id].dir<<"\n";
    }
    return 0;
}
int main(){
    cin >> b >>a;
    cin >> n >> m;
    bool flag = false;
    int id=1;
    for(int i=0;i<n;i++){
        int y,x; char z;
        int q,w;
        cin >> y >> x >> z;
        int dir;
        if(z == 'N') dir = 0;
        else if(z =='E') dir =1;
        else if(z =='S') dir =2;
        else dir =3;
        q=a-x; w=y-1;
        check[q][w] = id;
        robotMap.insert({id,Info(q,w,dir)});
        id++;
    }
    for(int i=0;i<m;i++){
        int orderId; char order; int cnt;
        cin >> orderId >> order >> cnt;
        int result = moveRobot(orderId,order,cnt);
        if(result == -1){
            cout << "Robot " << orderId << " crashes into the wall\n";
            flag = true;
            break;
        }
        
        else if(result > 0){
            cout << "Robot " << orderId << " crashes into robot "<< result<<"\n";
            flag = true;
            break;
        }
    }
    if(!flag) cout << "OK";
    // cout <<"\n";
    // for(auto it : robotMap){
    //     cout << it.second.x <<" , "<<it.second.y << " : " << it.second.dir <<"\n";
    // }
}