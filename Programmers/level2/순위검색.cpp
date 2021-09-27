#include<bits/stdc++.h>
using namespace std;
vector<int> db[5][5][5][5];
bool check[5][5][5][5];
vector<string> tokenizing(string str){
    stringstream ss(str);
    string token;
    vector<string> result;
    while(getline(ss,token,' ')){
        result.push_back(token);
    }
    return result;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    for(auto it : info){
        int a,b,c,d;
        vector<string> result = tokenizing(it);
        if(result[0] == "cpp") a = 0;
        else if(result[0] == "java") a = 1;
        else a = 2;
        
        if(result[1] == "backend") b = 0;
        else b = 1;
        
        if(result[2] == "junior") c = 0;
        else c = 1;
        
        if(result[3] == "chicken") d = 0;
        else d = 1;
        
        int score = stoi(result[4]);
        db[a][b][c][d].push_back(score);
        db[4][b][c][d].push_back(score);
        db[a][4][c][d].push_back(score);
        db[a][b][4][d].push_back(score);
        db[a][b][c][4].push_back(score);
        db[4][4][c][d].push_back(score);
        db[4][b][4][d].push_back(score);
        db[4][b][c][4].push_back(score);
        db[a][4][4][d].push_back(score);
        db[a][4][c][4].push_back(score);
        db[a][b][4][4].push_back(score);
        db[4][4][4][d].push_back(score);
        db[4][4][c][4].push_back(score);
        db[4][b][4][4].push_back(score);
        db[a][4][4][4].push_back(score);
        db[4][4][4][4].push_back(score);
    }
    
    for(auto it : query){
        vector<string> result = tokenizing(it);
        //02467
        int a,b,c,d;
        if(result[0] == "cpp") a = 0;
        else if(result[0] == "java") a = 1;
        else if (result[0] == "python") a = 2;
        else a = 4;
        
        if(result[2] == "backend") b = 0;
        else if(result[2] == "frontend") b = 1;
        else b = 4;
        
        if(result[4] == "junior") c = 0;
        else if(result[4] == "senior") c =1;
        else c = 4;
        
        if(result[6] == "chicken") d = 0;
        else if(result[6] == "pizza") d= 1;
        else d = 4;
        
        int score = stoi(result[7]);
        if(!check[a][b][c][d]){
            sort(db[a][b][c][d].begin(),db[a][b][c][d].end());
            check[a][b][c][d] = true;
        }
        auto iter = lower_bound(db[a][b][c][d].begin(),db[a][b][c][d].end(),score);
        int idx = db[a][b][c][d].end() - iter;
        answer.push_back(idx);

    }
    return answer;
}