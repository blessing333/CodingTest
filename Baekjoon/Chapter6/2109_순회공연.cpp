#include<bits/stdc++.h>
using namespace std;
int n,d,p,sum;
int arr[100001];
vector<pair<int,int>> v;

int main(){
    scanf("%d",&n);
    int de=0;
    
    for(int i=0;i<n;i++){
        //second = pay, first=day
        int p,d;scanf("%d%d",&p,&d);
        //arr[d-1]++;
        v.push_back({d,p});
        //cout << de<<". first = "<<v[de].first << "second = " <<v[de].second<<"\n";
        //de++;
    }
    printf("ddd");

    sort(v.begin(),v.end());
    for(int i=0;i<v.size();){
        int money=0;
        for(int j=i;j<j+arr[v[i].first-1];j++){
            money=max(money,v[j].first);
        }
        sum+=money;
        i+=arr[v[i].first-1];
    }
    cout <<sum;
}