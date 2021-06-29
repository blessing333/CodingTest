#include <bits/stdc++.h>

using namespace std;
vector<string> convertString(string time,char delimeter){
    stringstream ss(time);
    string token;
    vector<string> result;
    while(getline(ss,token,delimeter)){
        result.push_back(token);
    }
    return result;
}

int convertSecond(int hour,int minute,int second){
    return (hour * 3600) + (minute * 60) + second;
    
}

string convertStringSecond(int startIdx){
    int hour = startIdx/3600;
    string stringHour;
    if(hour <10) stringHour.push_back('0');
    stringHour=stringHour + to_string(hour) +":";
    startIdx%=3600;
    
    int minute = startIdx/60;
    string stringMinute;
    if(minute <10) stringMinute.push_back('0');
    stringMinute=stringMinute + to_string(minute) +":";
    startIdx%=60;
    
    string stringSecond;
    if(startIdx <10) stringSecond.push_back('0');
    stringSecond=stringSecond + to_string(startIdx);
    
    return stringHour + stringMinute + stringSecond;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    int arr[360000]={0};
    int maxSize;
    int adSize;
    vector<string> result = convertString(play_time,':');
    maxSize = convertSecond(stoi(result[0]),stoi(result[1]),stoi(result[2]));
    result = convertString(adv_time,':');
    adSize = convertSecond(stoi(result[0]),stoi(result[1]),stoi(result[2]));
    for(auto it : logs){
        int startTime,endTime;
        vector<string> string_time = convertString(it,'-');
        result=convertString(string_time[0],':');
        startTime = convertSecond(stoi(result[0]),stoi(result[1]),stoi(result[2]));
        result=convertString(string_time[1],':');
        endTime = convertSecond(stoi(result[0]),stoi(result[1]),stoi(result[2]));
        //cout << startTime<< "     " << endTime <<"      "<< convertStringSecond(startTime)<<"       "<< convertStringSecond(endTime)<<"\n";
        for(int i=startTime;i<endTime;i++) arr[i]++;
    }
    
    int startIdx =0;
    long long maximum = 0;
    for(int i = 0;i<adSize;i++){
        maximum+=arr[i];
    }
    
    int idx = adSize;
    int prev = 0;
    long long cur = maximum;
    while(idx<maxSize){
        cur-= arr[prev];
        cur+= arr[idx];
        if(cur > maximum){
            maximum = cur;
            startIdx = prev+1;
        }
        idx++;
        prev++;
    }
    return convertStringSecond(startIdx);
    
}