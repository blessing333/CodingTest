#include <bits/stdc++.h>

using namespace std;

int limitW = 0;
int limitH = 0;
bool isFit(int w,int h){
    return !(w>limitW || h>limitH);
}

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    for(auto it : sizes){
        if(isFit(it[0],it[1]) || isFit(it[1],it[0])) continue; // 들어가면 스킵
        int wDiff,hDiff,wDiff2,hDiff2;
        int sum1 = 0; int sum2 = 0;
        wDiff = it[0] - limitW;
        hDiff = it[1] - limitH;
        wDiff2 = it[1] - limitW;
        hDiff2 = it[0] - limitH;
        if(wDiff > 0) sum1 += wDiff;
        if(wDiff2 > 0) sum2 += wDiff2;
        if(hDiff > 0) sum1 += hDiff;
        if(hDiff2 >0) sum2 +=hDiff2;
        
        if(sum1 > sum2) {
            if(wDiff2 > 0)
                limitW = it[1];
            if(hDiff2 > 0)
            limitH = it[0];
        }
        else{
            if(wDiff > 0)
                limitW = it[0];
            if(hDiff > 0)
                limitH = it[1];
        }
        
    }

    cout << limitW << "  " << limitH;
    return limitW * limitH;
}