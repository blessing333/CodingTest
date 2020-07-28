#include<bits/stdc++.h>
using namespace std;

int n;
int x,y;
int arr[55];
pair<int,int> arr2[55];

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x >> y;
        arr[i]=1;
        arr2[i]=pair<int,int>(x,y);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr2[i].first>arr2[j].first && arr2[i].second>arr2[j].second)
                arr[j]++;
        }
    }

    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
}