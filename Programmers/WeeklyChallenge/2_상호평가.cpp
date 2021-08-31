#include <bits/stdc++.h>


using namespace std;
char getGrade(double grade){
    if(grade >= 90) return 'A';
    else if(grade >= 80) return 'B';
    else if(grade >= 70) return 'C';
    else if(grade >= 50) return 'D';
    else return 'F';
}
bool checkCondition(double key,vector<double> v){
    sort(v.begin(),v.end());
    double maximum = *max_element(v.begin(),v.end());
    double minimum = *min_element(v.begin(),v.end());
    if(key == maximum || key == minimum) return true;
    else return false;
}

bool checkUnique(double key,vector<double> v){
    int cnt = 0;
    for(auto it : v){
        if(it == key) cnt++;
        if (cnt > 1) return false;
    }
    return true;
}

string solution(vector<vector<int>> scores) {
    string answer = "";
    int n = scores.size();
    vector<double> score[10];
  
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            score[i].push_back(scores[j][i]);
        }
    }
    
    for(int i=0;i<n;i++){
        double key = score[i][i];
        double divider = n;
        bool isExtream = checkCondition(key,score[i]);
        bool isUnique = checkUnique(key,score[i]);
        double total = 0;
        for(auto it : score[i]){
            total += it;
        }
        if(isExtream && isUnique){
            total -= key;
            divider--;
        }
        answer.push_back(getGrade(total / divider));
        
    }
    return answer;
}