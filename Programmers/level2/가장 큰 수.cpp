#include <bits/stdc++.h>

using namespace std;
//사전순으로 뒤에 나오는게 먼저 나오면 가장 큰 수
// 더 큰게 늦게 나온다
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    for(int it : numbers){
        v.push_back(to_string(it));
    }
    sort(v.begin(),v.end(),greater<>());
    for(string it : v){
        answer+=it;
    }
    
    return answer;
}