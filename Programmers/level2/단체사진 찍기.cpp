#include<bits/stdc++.h>
using namespace std;
bool check[8];
vector<char> v;
int ret;
void permu(int n, vector<string> data, char clist[]){
    if(v.size()==8){
        for(auto it : data){
            char startAt=it[0];
            char endAt=it[2];
            char inequality = it[3];
            int dist=it[4]-'0';

            int startIdx=-1;
            int endIdx=-1;
            for(int i=0;i<8;i++){
                if(v[i] == startAt){
                    startIdx = i;
                }
                else if(v[i] ==endAt){
                    endIdx=i;
                }
            }
            int distance=abs(endIdx-startIdx)-1;
            switch (inequality){
            case '>' :
                if(!(distance>dist)) return;
                break;
            case '=' :
                if(distance!=dist) return;
                break;

            case '<' :
                if(!(distance<dist)) return;
                break;
            }
        }
        ret++;
    }
    else{
        for(int i=0;i<8;i++){
            if(check[i]) continue;
            check[i]=true;
            v.push_back(clist[i]);
            permu(n,data,clist);
            check[i]=false;
            v.pop_back();
        }
    }
}
int solution(int n, vector<string> data) {
    int answer = 0;
    ret=0;
    char clist[8]={'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    permu(n,data,clist);
    return ret;
}