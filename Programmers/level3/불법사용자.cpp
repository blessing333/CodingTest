#include<bits/stdc++.h>

using namespace std;
map<string,int> m;
int answer = 0;
vector<string> v2;
set<string> resultSet;

void dfs(int level,vector<vector<string>> candi){
    if(level == candi.size()){
        string str;
        vector<string> tmp = v2;
        sort(tmp.begin(),tmp.end());
        for(auto it : tmp){
            str +=it;
        }
        //cout << str<<"\n";
        resultSet.insert(str);
        return;
    }
    
    else{
        for(int i=0;i<candi[level].size();i++){
            if(m[candi[level][i]] != 0) continue;
            m[candi[level][i]]++;
            v2.push_back(candi[level][i]);
            dfs(level+1,candi);
            v2.pop_back();
            m[candi[level][i]]--;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    vector<vector<string>> result;
    for(auto banId : banned_id){
        vector<string> v;
        for(auto curId : user_id){
            if(curId.size() != banId.size()) continue;
            bool notMatching = false;
            for(int i=0;i<curId.size();i++){
                if(banId[i] != '*' && banId[i] != curId[i]){
                    notMatching = true;
                    break;
                }
            }
            if(notMatching) continue;
            v.push_back(curId);
        }
        result.push_back(v);
    }
    dfs(0,result);
    return resultSet.size();
}