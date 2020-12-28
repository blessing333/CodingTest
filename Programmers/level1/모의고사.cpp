#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr[3]={{1,2,3,4,5},{2,1,2,3,2,4,2,5},{3,3,1,1,2,2,4,4,5,5}};
    vector<int> answer;
    vector<int> ret;
    int maximum=0;
    for(int i=0;i<3;i++){
        int cnt=0;
        int idx=0;
        while(idx<answer.size()){
            for(auto it : arr[i]){
                if(it==answer[idx]){
                    cnt++;
                }
                idx++;
            }
        }
        cout << "cnt : " << cnt<<"\n";
        if(cnt!=0 && cnt>=maximum){
            maximum=cnt;
            ret.push_back(i+1);
        }
    }
}