#include<bits/stdc++.h>
using namespace std;
int h,w,x,y;
int arr[602][602];
int a[602][602];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> h >> w >> x >> y;
    
    for(int i=0;i<h+x;i++){
        for(int j=0;j<w+y;j++){
            cin >> arr[i][j];
        }
    }

    for(int i=0;i<x;i++){
        for(int j=0;j<w;j++){
            a[i][j] = arr[i][j];
        }        
    }

    for(int i=0;i<h;i++){
        for(int j=0;j<y;j++){
            a[i][j] = arr[i][j];
        }        
    };
    

    for(int i= 0+x;i<h+x;i++){
        for(int j=0+y;j<w+y;j++){
            a[i][j] = arr[i][j]-a[i-x][j-y];
        }
    }

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cout << a[i][j]<<" ";
        }
        cout <<"\n";
    }                               
}