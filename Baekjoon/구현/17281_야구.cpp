#include<bits/stdc++.h>
using namespace std;
int n;
bool check[9];
int info[50][9];
int batters[9];
int maximum = 0;

void logic(int batterArr[]){
    int curInning = 0;
    int score = 0;
    vector<int> rue;
    int curBatter = 0;
    int outCnt = 0;
    while(curInning < n){
        curBatter %= 9;
        int result = info[curInning][batters[curBatter++]];
        int sz= rue.size();

        if(result == 0) outCnt++;
        else if(result >= 1 && result <=3){
            int idx=0;
            for(int i=0;i<sz;i++){
                rue[idx] += result;
                if(rue[idx] >=4){
                    score++;
                    rue.erase(rue.begin()+idx);
                    idx--;
                }
                idx++;
            }
            rue.push_back(result);
        }
        else if(result == 4){
            score+= sz+1;
            rue.clear();
        }
        
        if(outCnt == 3){
            curInning++;
            outCnt=0;
            rue.clear();
        }
    }
    maximum = max(maximum,score);
}
void permu(int level){
    if(level == 9){
        logic(batters);
        return;
    }

    else if(level == 3){
        batters[3] = 0;
        permu(level+1);
        return;
    }

    else{
        for(int i=1;i<9;i++){
            if(check[i]) continue;
            check[i] = true;
            batters[level] = i;
            permu(level+1);
            check[i] = false;
        }
    }
}
int main(){
    //\freopen("output.txt","w",stdout);
    cin >> n;

    for(int i=0;i<n;i++){
        for(int j=0;j<9;j++){
            cin >> info[i][j];
        }
    }
    permu(0);
    cout << maximum;
}