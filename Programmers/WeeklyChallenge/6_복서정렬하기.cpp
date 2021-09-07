#include <bits/stdc++.h>
using namespace std;
struct Boxer{
    int id;
    double winRate;
    int heavyWin;
    int weight;
    Boxer(int a, double b, int c, int d){
        id = a; winRate = b; heavyWin = c; weight = d;
    }
};

bool comp(const Boxer &a, const Boxer &b){
    if(a.winRate == b. winRate){
        if(a.heavyWin == b.heavyWin){
            if(a.weight == b.weight){
                return a.id < b.id;
            }
            else return a.weight > b.weight;
        }
        else return a.heavyWin > b.heavyWin;
    }
    else return a.winRate > b.winRate;
}

vector<int> solution(vector<int> weights, vector<string> head2head) {
    vector<int> answer;
    vector<Boxer> boxers;
    for(int i=0;i<weights.size();i++){
        double winRate;
        string matchUp = head2head[i];
        int total = 0;
        int winCount = 0;
        int weight = weights[i];
        int heavy = 0;
        for(int j=0;j<matchUp.size();j++){
            if(matchUp[j] == 'W'){
                winCount++;
                if(weight < weights[j])
                    heavy++;
            }
            if(matchUp[j] !='N') total++;
        }
        
        if (total == 0) winRate = 0.0;
        else winRate = (double)winCount/(double)(total);
        
        boxers.push_back(Boxer(i,winRate,heavy,weight));
    }
    sort(boxers.begin(),boxers.end(),comp);
    for(auto it : boxers) answer.push_back(it.id+1);
    
    return answer;
}