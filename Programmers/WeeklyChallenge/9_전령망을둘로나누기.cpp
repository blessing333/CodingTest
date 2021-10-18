#include <bits/stdc++.h>

using namespace std;
int uni[101];
int check[101];
int cnt[101];
int minimum = INT_MAX;
int find(int a){
    if(uni[a] == a) return a;
    else return uni[a] = find(uni[a]);
}
void integrate(int a,int b){
    a = find(a);
    b = find(b);
    if(a!=b) uni[a] = b;
}

int solution(int n, vector<vector<int>> wires) {
    for(int i=0;i<n-1;i++){
        for(int j=1;j<=n;j++) {
            uni[j] = j;
            check[j] = false;
            cnt[j] = 0;
        }
        
        for(int j=0;j<n-1;j++){ // union 
            if(j == i) continue;
            int start = wires[j][0];
            int end = wires[j][1];
            integrate(start,end);
        }
        vector<int> candi;
        
        for(int j=1; j<=n;j++){ // 노드 개수 구하기
            int root = find(j);
            cnt[root]++;
            if(check[root]) continue;
            check[root] = true;
            candi.push_back(root);
        }
        minimum = min(minimum,abs(cnt[candi[0]]-cnt[candi[1]]));
    }
    return minimum;
}