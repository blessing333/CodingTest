#include<bits/stdc++.h>

using namespace std;
map<string,char> dic;
void initMap(){
    dic["zero"] = '0';
    dic["one"] = '1';
    dic["two"] = '2';
    dic["three"] = '3';
    dic["four"] = '4';
    dic["five"] = '5';
    dic["six"] = '6';
    dic["seven"] = '7';
    dic["eight"] = '8';
    dic["nine"] = '9';
}
int solution(string s) {
    string answer;
    initMap();
    int sz = s.size();
    string token;
    for(int i=0;i<sz;i++){
        char c = s[i];
        if(isdigit(c)){
            answer.push_back(c);
            continue;
        }
        else{
            token.push_back(c);
            if(dic.find(token) != dic.end()){
                answer.push_back(dic[token]);
                token = "";
            }
        }
    }
    
    return stoi(answer);
}