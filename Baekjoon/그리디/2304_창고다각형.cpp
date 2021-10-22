#include<bits/stdc++.h>
using namespace std;
int n;
int height[1001];
int lt = 1001,rt =-1,mid = 0;
vector<pair<int,int>> v;
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        int w,h;
        cin >> w >> h;
        height[w] = h;
        if(lt > w) lt = w;
        if(rt < w) rt = w;
        if(height[mid] < h) mid = w;
    }
    int curH = height[lt];
    int answer = 0;
    
    
    for(int i=lt; i<=mid; i++){
        if(height[i] > curH) curH = height[i];
        answer += curH;
    }
    
    curH = height[rt];
    for(int i=rt; i>mid; i--){
        if(height[i] > curH) curH = height[i];
        answer += curH;
    }
    cout << answer;
}