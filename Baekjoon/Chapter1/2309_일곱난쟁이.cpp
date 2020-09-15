#include<bits/stdc++.h>
using namespace std;
vector<int> v,v2;
int flag;
void combi(int here){
    if(flag)
        return;

    if(v2.size()==7){
        int sum=0;
        for(int i :v2){
            sum+=v[i];
        }
        if(sum==100){
            for(int i : v2){
                cout << v[i] << "\n";
            }
            flag=1;
            return;
        }
    }
    for(int i=here+1;i<9;i++){
        v2.push_back(i);
        combi(i);
        v2.pop_back();
    }

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n;
    for(int i=0;i<9;i++){
        cin >> n;
        v.push_back(n);
    }
    sort(v.begin(),v.end());
    combi(-1);
}