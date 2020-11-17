#include<bits/stdc++.h>
using namespace std;
int n,arr[101],tmp[101];
void merge(){

}

void divide(int lt, int rt){
    int mid=(lt+rt)/2;
    if(lt<rt){
        int p1=lt;
        int p2=mid+1;
        int p3=lt;        
        divide(lt,mid);
        divide(mid+1,rt);
        
        while(p1<=mid && p2<=rt){
            if(arr[p1]>arr[p2]){
                tmp[p3++]=arr[p2++];
            }
            else{
                tmp[p3++]=arr[p1++];
            }
        }

        while(p1<=mid){
            tmp[p3++]=arr[p1++];
        }
        while(p2<=rt){
            tmp[p3++]=arr[p2++];
        }
        for(int i=lt;i<=rt;i++){
            arr[i]=tmp[i];
        }
    }
    
}
int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    divide(1,n);
    for(int i=1;i<=n;i++){
        cout << arr[i] << " ";
    }
    
}
