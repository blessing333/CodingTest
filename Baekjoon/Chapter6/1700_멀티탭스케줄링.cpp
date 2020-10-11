#include<bits/stdc++.h>
using namespace std;
int n,k,arr[100],cnt,test;
vector<int> v;
int main(){
    cin >> n >> k;
    for(int i=0;i<k;i++){
        cin >> arr[i];
    }
    for(int i=0;i<k;i++){
        if(v.size()>0 && find(v.begin(),v.end(),arr[i])!=v.end())
            continue;
        if(v.size()==n){
            int maximum=-1;
            int index;
            for(int a=0;a<v.size();a++){ //멀티탭 각 구멍에 꽃힌 전자기기 별 반복
                int comp=INT_MAX;
                for(int j=i+1;j<k;j++){ // 가장 나중에 사용될 전자기기를 뒤에서부터 찾는다
                    if(arr[j]==v[a]){
                        comp=j;
                        break;
                    }
                }
                if(comp>=maximum){
                    maximum=comp;
                    index=a; //교체되어야할 벡터의 인덱스
                }
            }
            v[index]=arr[i];
            cnt++;
        }
        else{
            v.push_back(arr[i]);
        }
    }
    cout << cnt;
}