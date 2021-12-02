#include<bits/stdc++.h>
using namespace std;
int n,m;
int uni[201];
int arr[201][201];
int find(int a){
    if(uni[a] == a) return a;
    else return uni[a] = find(uni[a]);
}

void integrate(int a,int b){
    a = find(a);
    b = find(b);
    if(a!=b) uni[b] = a;
}

int main(){
    cin >> n;
    cin >> m;
    for(int i=1;i<=n;i++){
        uni[i] = i;
        for(int j=1;j<=n;j++){
            cin >> arr[i][j];
        }
    }
    for(int i=1;i<=n-1;i++){
        for(int j=i+1;j<=n;j++){
            if(arr[i][j] && find(i) != find(j))
                integrate(i,j);
        }
    }
    vector<int> dest;
    for(int i=0;i<m;i++){
        int a; cin >> a;
        dest.push_back(a);
    }
    int root = find(dest[0]);
    string result = "YES";
    for(auto it: dest){
        if(find(it) != root){
            result = "NO";
            break;
        }
    }
    cout << result;
}