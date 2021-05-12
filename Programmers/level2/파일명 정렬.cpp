#include<bits/stdc++.h>

using namespace std;
vector<string> tokenizing(string str){
    string header;
    string number;
    string tail;
    vector<string> result;
    int idx=0;
    while(!isdigit(str[idx])){
        header.push_back(str[idx]);
        idx++;
    }
    
    while(isdigit(str[idx])){
        number.push_back(str[idx]);
        idx++;
    }
    while(idx<str.size()){
        tail.push_back(str[idx]);
        idx++;
    }
    result.push_back(header);
    result.push_back(number);
    result.push_back(tail);
    return result;
    
}

bool comp(const string &s1, const string &s2){
    string s1_head,s2_head;
    string s1_number, s2_number;
    string s1_tail, s2_tail;
    
    vector<string> result = tokenizing(s1);
    s1_head = result[0];
    s1_number = result[1];
    s1_tail = result[2];
   
    
    result = tokenizing(s2);
    s2_head = result[0];
    s2_number = result[1];
    s2_tail = result[2];
    
    
    for(int i=0;i<s1_head.size();i++){
        if(islower(s1_head[i])){
            s1_head[i] = toupper(s1_head[i]);
        }
    }
    
    for(int i=0;i<s2_head.size();i++){
        if(islower(s2_head[i])){
            s2_head[i] = toupper(s2_head[i]);
        }
    }
    

    if(s1_head > s2_head) return false;
    else if(s1_head == s2_head){
        int n = stoi(s1_number);
        int n2 = stoi(s2_number);
        if(n>=n2) return false;
        else return true;
    }
    else return true;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    stable_sort(files.begin(),files.end(),comp);
    return files;
}