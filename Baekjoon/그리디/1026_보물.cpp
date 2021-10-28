#include<bits/stdc++.h>
using namespace std;
int n;
bool check[51];
vector<int> A;
vector<int> B;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++){
        int a; cin >> a;
        A.push_back(a);
    }
    for(int i=0;i<n;i++){
        int a; cin >> a;
        B.push_back(a);
    }
    int answer = 0;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end(),greater<int>());

    for(int i=0;i<n;i++) answer+= A[i]*B[i];
    cout << answer;
}