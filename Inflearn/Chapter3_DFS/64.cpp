#include<bits/stdc++.h>
using namespace std;

int v,e,vertex[20][20],cnt;
vector<int> vec;
bool check[20];
void go(int destination){
    if(destination==4){
        // for(auto it : vec){
        //     cout << it+1 << " ";
        // }
        // cout << "\n";
        cnt++;
    }
    else{
        for(int i=0;i<v;i++){
            if(vertex[destination][i] && !check[i]){
                check[i]=true;
                vec.push_back(i);
                go(i);
                vec.pop_back();
                check[i]=false;
            }
        }

    }
}
int main(){
    cin >> v >> e;
    for(int i=0;i<e;i++){
        int r,c;
        cin >> r >> c;
        vertex[--r][--c]=1;
    }
    check[0]=true;
    vec.push_back(0);
    go(0);
    cout << cnt;
}