#include<bits/stdc++.h>
using namespace std;
int check[100001];
bool cmp(int a,int b){
    return check[a] > check[b];
}
vector<int> solution(string s){
    int idx=1;
    vector<int> v;
    while(idx<s.size()){
        if(s[idx]=='{'){
            //cout << "idx : " << idx<<"\n";
            idx++;
            string num;
            while(s[idx]!='}'){
                if(s[idx] == ','){
                    //cout << "num is "<<num <<" at idx " <<idx <<"\n";
                    int intNum=stoi(num);
                    if(!check[intNum]) v.push_back(intNum);
                    check[intNum]++;
                    num="";
                }
                else if(s[idx] <= '9' && s[idx] >= '0') {
                    num.push_back(s[idx]);
                }
                idx++;
            }
            int intNum=stoi(num);
            if(!check[intNum]) v.push_back(intNum);
            check[intNum]++;
        }
        idx++;
    }
    sort(v.begin(),v.end(),cmp);
    return v;
}

int main(){
    string s;
    cin >> s;
    vector<int> a = solution(s);
    for(auto it : a){
        cout << it << " ";
    }
}