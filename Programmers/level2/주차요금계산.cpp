#include <bits/stdc++.h>

using namespace std;
map<string,vector<string>> inMap;
map<string,vector<string>> outMap; 
map<string,long long> parkTime;
vector<pair<int,int>> v;
vector<int> solution(vector<int> fees, vector<string> records) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long baseTime = fees[0] * 60;
    int baseFee = fees[1];
    long long unitTime = fees[2] * 60;
    int unitFee = fees[3];
    vector<int> answer;
    for(auto it : records){
        stringstream ss(it);
        string token;
        vector<string> result;
        while(getline(ss,token,' ')){
            result.push_back(token);
        }
        string time = result[0];
        string car = result[1];
        string state = result[2];
        
        if(state == "IN"){
            if(inMap.find(car) == inMap.end()){
                inMap.insert({car,vector<string>(1,time)});
            }
            else{
                inMap[car].push_back(time);
            }
        }
        else{
            if(outMap.find(car) == outMap.end()){
                outMap.insert({car,vector<string>(1,time)});
            }
            else{
                outMap[car].push_back(time);
            }
            
        }
    }
    
    for(auto it : inMap){
        string car = it.first;
        vector<string> inTimes= it.second;
        int sz = inTimes.size();
        if(outMap[car].size() != sz){
            outMap[car].push_back("23:59");
        }
        vector<string> outTimes = outMap[car];
        cout << "car number : " <<car<<"\n";
        for(int i=0;i<sz;i++){
            string outTime = outTimes[i]; // 16:30;
            string inTime = inTimes[i]; // 13:30
            
            string outStr;
            outStr.push_back(outTime[0]);
            outStr.push_back(outTime[1]);
            int outHour = stoi(outStr);
            outStr ="";
            outStr.push_back(outTime[3]);
            outStr.push_back(outTime[4]);
            int outMinute = stoi(outStr);
            long long outSec = outHour * 3600 + outMinute * 60;
            // cout << "outTime : " << outHour <<" " << outMinute << "sec : " <<outSec <<"\n";
            
            string inStr;
            inStr.push_back(inTime[0]);
            inStr.push_back(inTime[1]);
            int inHour = stoi(inStr);
            inStr ="";
            inStr.push_back(inTime[3]);
            inStr.push_back(inTime[4]);
            int inMinute = stoi(inStr);
            long long inSec = inHour * 3600 + inMinute * 60;
            // cout << "inTime : " << inHour <<" : " << inMinute << "sec : " <<inSec <<"\n";
            long long parkSec = outSec - inSec;
            
            if(parkTime.find(car) == parkTime.end()){ // 없으면
                parkTime.insert({car,parkSec});
            }
            else{
              parkTime[car]+= parkSec;
            } 
            
        }
    }
    for(auto it : parkTime){
        string car = it.first;
        int fee = baseFee;
        // cout << "car : "<<car<<"    time : "<<it.second  <<"\n";
        long long time = it.second - baseTime;
        if(time > 0){
            fee += time / unitTime * unitFee;
            if(time%unitTime !=0) fee+=unitFee;
        }
        // cout << car <<" " << fee <<"\n";
        v.push_back({stoi(car),fee});
    }
    sort(v.begin(),v.end());
    for(auto it : v){
        answer.push_back(it.second);
    }
    return answer;
}