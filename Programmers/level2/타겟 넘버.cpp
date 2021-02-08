#include <bits/stdc++.h>

using namespace std;
queue<int> q;
vector<int> v;
int answer=0;
void func(int cnt, int sum,int target,int sz,vector<int> v){
    if(cnt == sz){
        cout << sum <<"\n";
        if(sum == target) {
            answer++;
        }
        return;
    }
    else{
        func(cnt+1,sum+v[cnt],target,sz,v);
        func(cnt+1,sum-v[cnt],target,sz,v);
    }

}
int solution(vector<int> numbers, int target) {
    func(0,0,target,numbers.size(),numbers);
    return answer;
}