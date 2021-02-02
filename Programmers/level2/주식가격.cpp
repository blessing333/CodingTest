#include <bits/stdc++.h>
using namespace std;
vector<int> solution(vector<int> prices) {
    vector<int> answer;
    for(int i=0;i<prices.size()-1;i++){
        int price=prices[i];
        int pos;
        for(int j=i+1;j<prices.size();j++){
            int nextPrice=prices[j];
            pos=j;
            if(nextPrice<price) break;
        }
        answer.push_back(pos-i);
    }
    answer.push_back(0);
    return answer;
}