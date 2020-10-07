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
        arr[d-1]++;
        v.push_back({d,p});
        //cout << de<<". first = "<<v[de].first << "second = " <<v[de].second<<"\n";
        //de++;
    }
    
    sort(v.begin(),v.end());
    
    int index=0;
    for(int i=0;i<v.size();i++){
        cout << i;
        if(index>i) continue;
        int money=0;
        for(int j=i;j<i+arr[v[i].first-1];j++){
            money=max(money,v[j].second);
            cout << "j : " <<j<<"\n";
            cout << "arr[] : "<<j+arr[v[i].first-1] <<"\n";
        }
        sum+=money;
        printf("qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq");
        index=i+arr[v[i].first-1];
    }
    cout <<sum;
}