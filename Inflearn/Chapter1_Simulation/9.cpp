
#include<bits/stdc++.h>
using namespace std;
int arr[50001];
int n;
// int func(int num){ // n의 약수의 개수를 구하는 함수
//     int cnt=0;
//     for(int i=1;i<=num;i++){
//         if(num%i==0)
//             cnt++;
//     }
//     return cnt;
// }

int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j+=i){
            arr[j]++;
        }
    }
    for(int i=1;i<=n;i++){
        cout << arr[i] <<" ";
    }
}