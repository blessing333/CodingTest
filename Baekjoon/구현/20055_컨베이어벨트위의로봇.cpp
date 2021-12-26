#include<bits/stdc++.h>
using namespace std;
int n,k,m;
int main(){
    cin >> n >> k;
    vector<pair<int,int>> v(2*n,{0,0}); // 내구도, 로봇이 있는지
    for(int i=0;i<2*n;i++){
        int a;
        cin >> a;
        v[i] = {a,0};
    }
    int level = 0;
    int cnt = 0;
    vector<int> check(2*n,0);
    bool isDone = false;

    while(!isDone){
        level++;
        rotate(v.begin(),v.end()-1,v.end());
        v[n-1].second=0;
        for(int i=n-2;i>=0;i--){
            if(v[i].second != 1) continue;
            pair<int,int> cur = v[i];
            pair<int,int> next = v[i+1];
            if(next.second == 0 && next.first >= 1){ // 다음칸에 로봇이 없고 내구도가 1이상이면 이동
                v[i].second = 0;
                v[i+1].first--;
                if(v[i+1].first == 0){
                    cnt++;
                    if(cnt >= k){
                        isDone = true;
                        break;
                    }
                }
                v[i+1].second = 1;
            }
        }
        if(isDone) break;
        v[n-1].second = 0;

        if(v[0].first >= 1){
            v[0].second = 1;
            v[0].first--;
            if(v[0].first == 0){
                cnt++;
                if(cnt >= k){
                    isDone = true;
                    break;
                }
            }
        }
        if(isDone) break;
    }
    cout << level;
}