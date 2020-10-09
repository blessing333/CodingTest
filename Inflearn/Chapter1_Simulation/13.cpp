#include<bits/stdc++.h>
using namespace std;
string str; int maximum=-1,result;
int arr[10];
int main(){
    cin >> str;
    for(auto it : str){
        arr[it-'0']++;
    }
    for(int i=0;i<10;i++){
        if(arr[i]>maximum){
            result=i;
            maximum=arr[i];
        }
        else if(arr[i]==maximum && result<i){
            result=i;
        }
    }
    cout << result;
}