#include<bits/stdc++.h>
using namespace std;
map<string,int> m;
int n;
int main(){
    cin >> n;
    cin.ignore();
    for(int i=0;i<n;i++){
        string s;
        string token;
        vector<string> result;
        getline(cin,s);
        for(auto it : s){
            if(it == ' '){
                result.push_back(token);
                token = "";
            }
            else
                token.push_back(it);
        }
        result.push_back(token);
        //cout << result[0] <<"   "<<result[1]<<"\n";
        if(result[1] == "enter"){
            m[result[0]]++;
        }
        else
            m.erase(result[0]);
    }
    
    for(auto iter =m.rbegin();iter != m.rend(); iter++){
        cout << iter->first <<"\n";
    }

}