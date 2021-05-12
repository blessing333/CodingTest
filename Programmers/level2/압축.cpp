#include <bits/stdc++.h>

using namespace std;
map<string,int> dictionary;

string findLongestString(string input){
    string result;
    auto end = dictionary.end();
    while(input.size() >= 1){
        if(dictionary.find(input) != end){
            result = input;
            break;
        }
        input.pop_back();
    }
    return result;
}

vector<int> solution(string msg) {
    int size = msg.size();
    vector<int> answer;
    int value =1;
    for(char c='A';c<='Z';c++){
        string id=""; id.push_back(c);
        dictionary[id] = value++;
    }
    
    while(msg.size() > 0){
        string w = findLongestString(msg);
        answer.push_back(dictionary[w]);
        msg = msg.substr(w.size());
        if(msg.size() > 0){
            w.push_back(msg[0]);
            dictionary[w] = value++;
        }
    }

    return answer;
}