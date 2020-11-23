#include<bits/stdc++.h>
using namespace std;
int uni[1001];
int find(int a){
    if(a==uni[a]) return a;
    else return uni[a]=find(uni[a]);
}

void integrate(int a, int b){
    a=find(a);
    b=find(b);
    if(a!=b) uni[a]=b;
}

int main(){
    int n,m,start,end;
    cin >> n >>m;
    for(int i=1;i<=n;i++) uni[i]=i;
    for(int i=1;i<=m;i++){
        int a,b;
        cin >> a >> b;
        integrate(a,b);
    }
    cin >> start >> end;
    if(find(start)==find(end)) cout << "YES";
    else cout << "NO";

}