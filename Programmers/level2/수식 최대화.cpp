#include<bits/stdc++.h>
using namespace std;
vector<char> op;
vector<string> num;
set<char> oper;
vector<char> v;
long long answer = 0;
bool check[3];

string calc(string num1,string num2,char op){
    long long n1 = stoll(num1);
    long long n2 = stoll(num2);
    long long result;
    if(op == '+') result = n1+n2;
    else if(op == '-') result = n1-n2;
    else result = n1*n2;
    return to_string(result);
}
void permu(){
    if(v.size() == oper.size()){
        vector<char> opTmp = op;
        vector<string> numTmp = num;
        
        for(int i=0;i<v.size();i++){
            char curOper = v[i];
            for(int j=0;j<opTmp.size();j++){
                char it = opTmp[j];
                if(it == curOper){
                    string result = calc(numTmp[j],numTmp[j+1],it);
                    numTmp[j] = result;
                    numTmp.erase(numTmp.begin()+j+1);
                    opTmp.erase(opTmp.begin() + j);
                    j--;
                }
            }
        }
        long long numResult = stoll(numTmp[0]);
        answer = max(abs(numResult),answer);
    }
    else{
        for(int i=0;i<oper.size();i++){
            if(check[i]) continue;
            check[i] = true;
            auto iter = oper.begin();
            advance(iter,i);
            v.push_back(*iter);
            permu();
            v.pop_back();
            check[i] = false;
        }
    }
}

long long solution(string expression) {
    
    string str;
    for(auto it : expression){
        if(isdigit(it)){
            str.push_back(it);
        }
        else{
            num.push_back(str);
            op.push_back(it);
            oper.insert(it);
            str = "";
        }
    }
    num.push_back(str);
    permu();
    return answer;
}