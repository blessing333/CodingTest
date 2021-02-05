#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(auto it : commands){    
        int i=it[0];
        int j=it[1];
        int k=it[2];
        vector<int> v(array.begin()+i-1,array.begin()+j);
        sort(v.begin(),v.end());
        answer.push_back(v[k-1]);
    }
    return answer;
    
    
}