#include<bits/stdc++.h>

using namespace std;
int getGrade(int score){
    int result;
    if(score >= 6) return 1;
    else if(score >= 5) return 2;
    else if(score >= 4) return 3;
    else if(score >= 3) return 4;
    else if(score >= 2) return 5;
    else return 6;
    
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    bool check[46] ={0,};
    for(int num : win_nums){
        check[num] = true;
    }
    int zeroCount = 0;
    int minimum =0;
    for(int num : lottos){
        if(num == 0){
            zeroCount++;
            continue;
        }
        if(check[num]) minimum++;
    }
    int maximum = minimum+zeroCount;
    answer.push_back(getGrade(maximum));
    answer.push_back(getGrade(minimum));
    return answer;
}