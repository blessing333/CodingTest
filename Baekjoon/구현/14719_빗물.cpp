#include<bits/stdc++.h>
using namespace std;
int w,h;
int height[501];
int main(){
    cin >> h >> w;
    for(int i=0;i<w;i++){
        int a; cin >> a;
        height[i] = a;
    }
    int answer = 0;
    for(int i=1;i<w-1;i++){
        int left = -1;
        int right = -1;
        int cur = height[i];
        int lower;
        for(int j=i-1; j>=0; j--) left = max(left,height[j]);
        for(int j=i+1; j<w; j++) right = max(right,height[j]);
        lower = min(left,right);
        if(lower > cur ) answer += (lower - cur);   
    }
    cout << answer;
}