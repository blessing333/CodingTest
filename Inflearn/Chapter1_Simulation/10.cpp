#include<bits/stdc++.h>
using namespace std;
int n,num,result,maximum;
int digit_sum(int x){
    int sum=0;
    while(x>0){
        int d= x%10;
        sum+=d;
        x/=10;
    }
    return sum;
}

int main(){
    int a;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> num;
        a=digit_sum(num);

        if(a>maximum){
            maximum=a;
            result=num;
        }
        else if(a==maximum){
            if(num>result){
                result = num;
            }
        }       
    }
    cout << result;
}