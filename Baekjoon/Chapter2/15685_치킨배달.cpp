#include<bits/stdc++.h>
using namespace std;
int n,m,board[50][50],ret=INT_MAX;
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
bool visited[50][50];
vector<pair<int,int>> v;
vector<pair<int,int>> candi;
vector<pair<int,int>> home;
queue<pair<int,int>> q;
void combi(int here){
    if(candi.size()==m){
        int total=0;
        for(auto it : home){
            int perChicken=INT_MAX;
            pair<int,int> curHome=it;
            for(auto chiken : candi){
                pair<int,int> curChiken=chiken;
                int dist=abs(curChiken.first-curHome.first)+abs(curChiken.second-curHome.second);
                perChicken=min(perChicken,dist);
            }
            total+=perChicken;
        }
        ret=min(total,ret);
        return;
    }

    for(int i=here+1;i<v.size();i++){
        candi.push_back(v[i]);
        combi(i);
        candi.pop_back();
    }
}

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> board[i][j];
            if(board[i][j]==2){
                v.push_back({i,j});
            }
            else if(board[i][j]==1)
                home.push_back({i,j});
        }
    }
    combi(-1);
    cout << ret;
}