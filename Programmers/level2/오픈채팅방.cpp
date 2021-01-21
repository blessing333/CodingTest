#include<bits/stdc++.h>
using namespace std;
struct P{
    string command;
    string uid;
    string id;
};

vector<string> solution(vector<string> record) {
    map<string,string> uidMap;
    vector<pair<string,string>> logList;
    vector<string> ret;

    for(int i=0;i<record.size();i++){
        P cur;
        string it = record[i];
        string token;
        int flag=0; //0 : coomand   1: uid      2: id
        for(int j=0;j<=it.size();j++ ){
            char c=it[j];
            if(c == ' ' || j==it.size()){
                if(flag == 0) cur.command = token;
                else if(flag == 1) cur.uid = token;
                else if(flag == 2) cur.id=token;
                token = "";
                flag=(flag+1)%3;       
            } 
            else token.push_back(c);
        }
        logList.push_back({cur.command,cur.uid});
        if(cur.command=="Enter" || cur.command=="Change") uidMap[cur.uid]=cur.id;
    }
    
    for(auto it : logList){
        string str;
        string curId=uidMap[it.second];
        if(it.first=="Enter"){
            str=curId+"님이 들어왔습니다.";
            ret.push_back(str);
        }
        else if(it.first=="Leave"){
            str=curId+"님이 나갔습니다.";
            ret.push_back(str);
        }
    }
    return ret;
}