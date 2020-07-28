#include<bits/stdc++.h>
using namespace std;
vector<int> v1;
int sum=0;
int n;
void func(){
    for(int i=0;i<8;i++){
        for(int j=i+1;j<9;j++){
            if(sum-(v1[i]+v1[j])==100){
                v1[i]=0;
                v1[j]=0;
                return;
            }
        }
    }
}
int main(){
    for(int i=0;i<9;i++){
        scanf("%d",&n);
        v1.push_back(n);
        sum+=n;
    }   
    func();
    sort(v1.begin(),v1.end());
    for(int ret :v1){
        if(ret!=0)
        printf("%d ",ret);
    }
}