#include <bits/stdc++.h>
using namespace std;
int uni[201];
bool check[201];
int find(int a){
    if(uni[a]==a) return a;
    else return uni[a]=find(uni[a]);
}

void integrate(int a, int b){
    a=find(a);
    b=find(b);
    if(a!=b) uni[a]=b;
}

int solution(int n, vector<vector<int>> computers) {
    int answer =0;
    for(int i=1;i<=n;i++) uni[i]=i;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           if(i==j) continue;
           if(computers[i][j]) integrate(i+1,j+1);
        }   
    }
    for(int i=1;i<=n;i++) check[find(i)]=true;
    for(int i=1;i<=n;i++) if(check[i]) answer++;
    return answer;
}