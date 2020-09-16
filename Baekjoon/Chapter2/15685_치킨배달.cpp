/*
    부르트포스,조합
    주어진 치킨집 중 m개의 치킨집을 골라 치킨 거리가 최소가 되는 경우를 출력
*/
#include<bits/stdc++.h>
using namespace std;
int n,m,k, result=98765543;
vector<pair<int,int>> home,chk,v;
int getDist(int x1,int y1,int x2,int y2){
    return abs(x1-x2) + abs(y1-y2);
}
void combi(int here){
    if(v.size()==m){
        int total=0;
        for(auto it : home){
            int least=987654321;
            for(auto it2:v){
                least=min(least,getDist(it.first,it.second,it2.first,it2.second));
            }
            total+=least;
        }
        result=min(total,result);
        return;
    }

    for(int i=here+1;i<chk.size();i++){
        v.push_back(chk[i]);
        combi(i);
        v.pop_back();
    }
}
int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> k;
            if(k==1){
                home.push_back({i,j});
            }
            else if(k==2){
                chk.push_back({i,j});
            }
        }
    }
    combi(-1);
    cout<< result;
}