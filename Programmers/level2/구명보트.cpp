#include<bits/stdc++.h>
using namespace std;
int solution(vector<int> people, int limit) {
    int front=0;
    int cnt=0;
    int sz=people.size();
    int back=sz-1;
    sort(people.begin(),people.end(),greater<>());
    while(front<=back){
        if(people[front]<=limit/2){
            cnt+=ceil((back+1-front)/2.0);
            break;
        }

        if(people[front]+people[back]<=limit){
            front++;
            back--;
        }
        else{
            front++;
        }
        cnt++;
    }
    return cnt;
    
}