#include<bits/stdc++.h>
using namespace std;
vector<string> participant;
vector<string> completion;
unordered_map<string,int> m;

int main(){
    participant.push_back("Minjae");
    participant.push_back("Jaemin");
    for(auto it : participant){
        m[it];
    }
    for(auto it : m){
        cout << it.first << " : " << it.second << "\n";
    }
    
}