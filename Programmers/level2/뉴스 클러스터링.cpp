#include<bits/stdc++.h>


using namespace std;
void createToken(string str, vector<string> &set1){
    string token;
    int idx=0;
    while(idx<str.size()){
        bool check=true;
        string token=str.substr(idx,2);
        idx+=2;
        if(token.size()<2) break;
        for(int i=0;i<token.size();i++){
            char it = token[i];
            if((!(it >='a' && it<='z') && !(it >='A' && it<='Z'))) check=false;
            else if(it >='A' && it<='Z') token[i]+=32;
        }
        if(check){
            set1.push_back(token);
        }
    }


}
int solution(string str1, string str2) {
    long long ret=0;
    vector<string> set1,set2,intersectionSet,unionSet;
    string token;
    int idx=0;
    createToken(str1,set1);
    createToken(str2,set2);

    sort(set1.begin(),set1.end());
    sort(set2.begin(),set2.end());

    intersectionSet.resize(set1.size());
    unionSet.resize(set1.size()+set2.size());

    set_intersection(set1.begin(),set1.end(),set2.begin(),set2.end(),intersectionSet.begin());
    set_union(set1.begin(),set1.end(),set2.begin(),set2.end(),unionSet.begin());

    if(unionSet.size()==0)
        return 0;
    else 
        return intersectionSet.size()/
    
    for(auto it : set1){
        cout << it << "\n";
    }
    cout << "\n";
    
    // for(auto it : set2){
    //     cout << it << "\n";
    // }
    return 0;
}

int main(){
    string str1,str2;
    cin >> str1 >> str2;
    solution(str1,str2);
}