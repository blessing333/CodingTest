#include<bits/stdc++.h>
using namespace std;
int answer;
int r,c;
vector<int> v;
unordered_map<string,int> candidate;
bool check[8];
bool canCandidate=true;

void checkPoserset(int n){
    if(n==v.size()){
        string id="";
        for(int i=0;i<n;i++){
            if(check[i]) continue;
            id+=v[i]; 
        }
        auto iter = candidate.find(id);
        if(iter != candidate.end()){ //후보키가 될 수 없다
            canCandidate=false;
        }
    }
    else{    
        check[n]=true;
        checkPoserset(n+1);
        check[n]=false;
        checkPoserset(n+1);
    }
}

void combi(int cnt,int here,vector<vector<string>> relation){
    if(v.size() == cnt){
        //최소성 만족하는지 확인
        canCandidate=true;
        checkPoserset(0);
        
        if(canCandidate){//유일성 만족하는지 확인
            bool flag=true;
            unordered_map<string,int> m;
            for(auto it : relation){
                string id="";
                for(int idx : v){
                    id+=it[idx];
                }
                m[id]++;
            }
        
            for(auto it : m){
                cout << "id : "<<it.first <<" value : "<< it.second <<"\n";
                if(it.second>1){
                    flag=false;
                    break;
                }
            }
            
            if(flag){
                answer++;
                string candiId;
                for(auto it : v){
                    candiId+=it;
                }
                candidate[candiId]++;
            }
            cout <<"\n\n";
        }
    }

    else{
        for(int i=here+1; i<c;i++){
            v.push_back(i);
            combi(cnt,i,relation);
            v.pop_back();
        }
    }

}

int solution(vector<vector<string>> relation) {
    r=relation.size();
    c=relation[0].size();
    for(int i=1;i<=c;i++){
        combi(i,-1,relation);
    }
    return answer;
    
}