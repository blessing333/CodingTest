#include<bits/stdc++.h>
using namespace std;
int n,m,minimum=INT_MAX,result=1;
vector<int> v,v2; // v : 석순   v2 : 종유석

/*
    row를 전달받아 파괴하는 석순과 종유석의 개수를 구하는 함수
        1.파괴되는 석순 구하기
        - row보다 큰 석순의 개수를 구한다.
        2.파괴되는 종유석 갯수 구하기
        - (h-종유석의 길이)가 row보다  큰경우
*/
void func(int row){
    int a= v.end() - upper_bound(v.begin(),v.end(),row);
    int b=lower_bound(v2.begin(),v2.end(),row)-v2.begin()-1;
    //cout <<"\n\n"<< a << "\n" <<b<<"\n";
    int sum=a+b;
    if(sum<minimum){
        minimum=sum;
        result=1;
    }
    else if(sum==minimum){
        result++;
    }
}

/*
    모든 row에 대해서 반복.
        -현재 row에서  파괴하는 석순과 종유석의 갯수를 구한다.
*/
int main(){
    cin >> m >> n;
    for(int i=1;i<=m;i++){
        int k; cin >> k;
        if(i%2==1){
            v.push_back(k);
        }
        else{
            v2.push_back(n-k);
        }
    }
    sort(v.begin(),v.end());
    sort(v2.begin(),v2.end());
    //func(1);
    for(int i=1;i<=n;i++){
        func(i);
    }
    cout << minimum << " " <<result;
}