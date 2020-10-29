#include<bits/stdc++.h>
using namespace std;
int n,m,lt=1,rt;
vector<int> v;

bool condition(int mid){
    int dist; int cnt=m-1;
    int cur=0,next=cur+1;
    while(cnt>0){
        dist=v[next]-v[cur];
        if(dist>=mid){
            cnt--;
            cur=next;
        }
        if(next==n-1)
            return false;
        next++;
    }
    return true;
}
int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        int a; cin >> a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    rt=v[n-1];
    int result=0;
    while(lt<rt){
        int mid=(lt+rt)/2;
        //cout << "\n" << mid << "        "<< condition(mid)<<"\n";
        if(condition(mid)){
            lt=mid+1;
            result=max(result,mid);
        }
        else{
            rt=mid-1;
        }
        
    }
    cout << result;
}