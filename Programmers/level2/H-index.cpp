#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(),citations.end());
    int h=0;
    bool flag=true;
    while(flag){
        int count=citations.end()-lower_bound(citations.begin(),citations.end(),h);
        if(count<h){
            flag=false;
            h--;
            break;
        }
        h++;
    }
    return h;
}