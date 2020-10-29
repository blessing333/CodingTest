#include<bits/stdc++.h>
using namespace std;
int n,m,arr[1000],sum,lt,rt;
bool condition(int mid){
    int sum=0,cnt=1;
    for(int i=0;i<n;i++){
        if(sum+arr[i]<=mid){
            sum+=arr[i];
        }
        else{
            sum=arr[i];
            cnt++;
        }
        if(cnt>m){
            return false;
        }
    }
    return true;
}

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        rt+=arr[i];
        lt=max(lt,arr[i]);
    }
    int mid;
    int answer=rt;
    while(lt<=rt){
        mid=(lt+rt)/2;
        if(condition(mid)){
            answer=min(answer,mid);
            rt=mid-1;
        }
        else{
            lt=mid+1;
        }
    }
    cout << answer;
}
