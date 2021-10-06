#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<long> v;
long long logic(long long target){
    long long sum=0;
    for(auto it : v){
        sum= sum + it/target;
    }
    return sum;
}

int main(){
    cin >> k >> n;
    long answer = 0;
    for(int i=0;i<k;i++){
        int a; cin >> a;
        v.push_back(a);
    }
    long long sum=0;
    for(auto it : v) sum+=it;
    
    long long left = 1;
    long long right = sum / n; //inclusive
    
    while(left<=right){
        long long mid = (left + right)/2;
        if(logic(mid) < n){
            right = mid-1;
        }
        else{
            left = mid+1;
        }
    }
    cout << right;
}