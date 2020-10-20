#include<bits/stdc++.h>
using namespace std;
int n,k;
priority_queue<int> q;
vector<pair<int,int>> gem;
vector<int> bag;

int main(){
    cin >> n >> k;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        gem.push_back({a,b});
    }
    for(int i=0;i<k;i++){
        int a; cin >> a;
        bag.push_back(a);
    }
    long long sum=0;
    sort(gem.begin(),gem.end());
    sort(bag.begin(),bag.end());
    int index=0;
    for(int i=0;i<k;i++){
        while(index<n){
            if(bag[i]>=gem[index].first){
                q.push(gem[index].second);
                index++;
            }
            else
                break;
        }
        if(!q.empty()){
            sum+=q.top();q.pop();
        }
    }
    cout << sum;
}