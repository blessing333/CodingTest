#include<bits/stdc++.h>
using namespace std;
unordered_map<string,int> m;

string solution(vector<string> participant, vector<string> completion){
    for(auto it : participant){
        ++m[it];
    }
    
    for(auto it : completion){
        --m[it];
    }
    
    for(auto it : m){
        if(it.second>0){
            return it.first;
        }
    }
}