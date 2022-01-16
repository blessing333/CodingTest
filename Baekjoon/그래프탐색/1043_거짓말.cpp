#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int answer = 0;
int check[51];
vector<int> know;
int uni[51];
vector<vector<int>> parties;

int find(int v){
    if(uni[v] == v) return v;
    else return uni[v] = find(uni[v]);
}

void integrate(int a,int b){
    a = find(a);
    b = find(b);
    if(a!=b) uni[b] = a;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    cin >> k;
    for(int i=1;i<=n;i++) uni[i] = i;
    
    for(int i=0;i<k;i++){ // 아는사람
        int a; cin >> a;
        know.push_back(a);
    }

    for(int i=0;i<m;i++){ // 파티 참석자
        vector<int> v;
        int b; cin >> b;
        for(int j=0;j<b;j++){
            int c; cin >> c;
            v.push_back(c);
        }
        parties.push_back(v);
    }

    for(vector<int> joiner : parties){ // 모든 파티에  참석한 사람에 대하여 union 자료구조 생성
        int sz = joiner.size();
        int base = joiner[0];
        for(int i=1;i<sz;i++){
            int target = joiner[i];
            if(find(base) != find(target)){
                integrate(base,target);
            }
        }
    }
    
    for(auto it : know){
        check[find(it)] = true;
    }

    for(vector<int> joiner : parties){ // 모든 파티에  참석한 사람에 대하여 union 자료구조 생성
        bool result = false;
        for(auto it : joiner){
            if(check[find(it)]){
                result = true;
                break;
            }
        }
        if(!result) answer++;
    }

    cout << answer;

}