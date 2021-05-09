#include <bits/stdc++.h>

using namespace std;

int COST = 100;
map<string,string> parentMap;
map<string,int> priceMap;

void createParentTree(vector<string> enroll, vector<string> referral){
    int size = enroll.size();
    for(int i=0;i<size;i++){
        string childName = enroll[i];
        string parentName = referral[i];
        parentMap[childName] = parentName;
    }
}

void calculate(vector<string> seller, vector<int> amount){
    int size = seller.size();
    for(int i=0;i<size;i++){
        string sellerName = seller[i];
        string parentName = parentMap[sellerName];
        int sellAmount = amount[i];
        int totalBenefit = COST * sellAmount;
        int parentBenefit = totalBenefit / 10;
        int sellerBenefit = totalBenefit - parentBenefit;
        priceMap[sellerName] += sellerBenefit;
        
        while(parentName !="-"){
            sellerName = parentName;
            parentName = parentMap[sellerName];
            sellerBenefit = parentBenefit;
            parentBenefit = sellerBenefit /10;
            sellerBenefit -= parentBenefit;
            priceMap[sellerName] += sellerBenefit;
        }
    }
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    createParentTree(enroll,referral);
    calculate(seller,amount);
    for(auto name : enroll) answer.push_back(priceMap[name]);
    return answer;
}