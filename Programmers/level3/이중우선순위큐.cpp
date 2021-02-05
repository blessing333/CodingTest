#include<bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> operations) {
    deque<int> q;
    for(auto it : operations){
        stringstream ss(it);
        string token;
        char delimeter = ' ';
        vector<string> result;
        while(getline(ss,token,delimeter)){
            result.push_back(token);
        }
        string command = result[0];
        int value = stoi(result[1]);
        if(command == "I"){
            q.push_back(value);
        }
        else if(!q.empty() && command == "D"){
            auto iter = value>0 ? max_element(q.begin(),q.end()) : min_element(q.begin(),q.end());
            q.erase(iter);
        }
    }
    vector<int> answer;
    if(q.size()>0){
        answer.push_back(*max_element(q.begin(),q.end()));
        answer.push_back(*min_element(q.begin(),q.end()));
    }
    else{
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}