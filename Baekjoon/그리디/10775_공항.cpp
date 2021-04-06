#include<bits/stdc++.h>
using namespace std;
int g,p;
vector<int> uni;
int find(int a){
    if(uni[a] == a) return a;
    else return uni[a] = find(uni[a]);
}

void integrate(int a,int b){ // a를 b에 연결한다.
    if(find(a) != find(b))
        uni[a] = b;
}

int main(){
    cin >> g;
    cin >> p;
    
    for(int i=0;i<=g;i++){
        uni.push_back(i);
    }
    int cnt =0;
    for(int i=0;i<p;i++){
        int plane;
        cin >> plane;
        if(find(plane) == 0) break;
        int idx = find(plane);
        integrate(idx,idx-1);
        cnt++;
    }
    cout << cnt;
}