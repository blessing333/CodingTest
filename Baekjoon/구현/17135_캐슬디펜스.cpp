#include<bits/stdc++.h>
using namespace std;
int n,m,d;
int board[16][16];
int maximum = 0;
vector<int> v;
struct EnemyInfo{
    int x;
    int y;
    int dist;
};

bool comp(const EnemyInfo &a, const EnemyInfo &b){
    if(a.dist == b.dist){
        return a.y < b.y;
    }
    else return a.dist < b.dist;
}

int getDist(int x1, int y1, int x2, int y2){
    return abs(x1-x2) +abs(y1-y2);
}

vector<pair<int,int>> findEnemy(int arr[16][16]){
    vector<pair<int,int>> result;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] == 1){
                result.push_back({i,j});
            }
        }
    }
    return result;
}

void move(int arr[][16]){
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(arr[i][j] == 1){
                arr[i][j] = 0;
                if(i != n-1) arr[i+1][j] =1;
            }
        }
    }
}

void combi(int here){
    if(v.size() == 3){
        int kill = 0;
        int tmp[16][16];
        copy(&board[0][0],&board[0][0]+16*16,&tmp[0][0]);
        while(true){
            vector<pair<int,int>> enemyPos = findEnemy(tmp);
            int enemyCnt = enemyPos.size();
            if(enemyCnt == 0) break;
            vector<EnemyInfo> enemyInfo[3];
            for(int i=0;i<3;i++){
                int archerY = v[i];
                for(int j=0; j<enemyCnt; j++){
                    int x=enemyPos[j].first;
                    int y=enemyPos[j].second;
                    int d = getDist(n,archerY,x,y);
                    EnemyInfo enemy;
                    enemy.x=x;
                    enemy.y=y;
                    enemy.dist = d;
                    enemyInfo[i].push_back(enemy);
                }
                sort(enemyInfo[i].begin(),enemyInfo[i].end(),comp);
            }
            for(int i=0;i<3;i++){
                EnemyInfo target = enemyInfo[i][0];
                if(target.dist <= d && tmp[target.x][target.y] == 1){
                    kill++;
                    tmp[target.x][target.y] = 0;
                }
            }
            move(tmp);
        }
        maximum = max(maximum,kill);
    }
    else{
        for(int i=here+1;i<m;i++){
            v.push_back(i);
            combi(i);
            v.pop_back();
        }
    }
}
int main(){
    cin >> n >> m >> d;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
        }
    }
    combi(-1);
    cout << maximum;
}