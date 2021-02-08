#include <bits/stdc++.h>
using namespace std;
bool cmp(const vector<int> a, const vector<int> b){
    return a[1]<b[1];
}
int solution(vector<vector<int>> routes) {
    int answer=0;
    sort(routes.begin(),routes.end(),cmp); // 진출점을 기준으로 오름차순 정렬
    while(!routes.empty()){
        int spot = routes[0][1]; //최초 진출이 발생하는 구역
        int sz=routes.size();
        int idx=0;
        for(int i=0;i<sz;i++){//진입점이 spot보다 작은애들은 삭제
            if(routes[idx][0]<=spot){
                routes.erase(routes.begin()+idx);
                idx--;
            }
            idx++;
        }
        answer++;
    }
    return answer;
}