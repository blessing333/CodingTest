/*
    1. 
    2. 팀1을 조합으로 구한다
    3. 
*/
#include<bits/stdc++.h>
using namespace std;
int n,board[20][20],result=987654321;

vector<int> v,v1;

int check[20];

void combi(int here){    
    if(v.size()==n/2){
        int total=0;
        int total2=0;
        int diff;
        //선택된 팀 능력치 합
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v.size();j++){
                if(i==j) continue;
                total+=board[v[i]][v[j]];
            }
        }
        //안선택된 팀 능력치 합
        for(int i=0;i<n;i++){
            if(check[i]==0){
                v1.push_back(i);
            }
        }
        
        for(int i=0;i<v1.size();i++){
            for(int j=0;j<v1.size();j++){
                if(i==j) continue;
                total2+=board[v1[i]][v1[j]];
            }
        }
        v1.clear();
        diff=abs(total-total2);
        result=min(result,diff);
        return;
    }

    for(int i=here+1;i<n;i++){
        if(check[i]==1)continue;
        check[i]=1;
        v.push_back(i);
        combi(i);
        check[i]=0;
        v.pop_back();
    }
}

int main(){
    cin >> n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >>board[i][j];
        }
    }

    for(int i=n; i<20;i++)
        check[i]=3;
    combi(-1);
    cout << result;
}