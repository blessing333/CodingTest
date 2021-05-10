#include <bits/stdc++.h>

using namespace std;
vector<string> tokenizing(string str,char delimeter){
    stringstream ss(str);
    vector<string> result;
    string token;
    while(getline(ss,token,delimeter)){
        result.push_back(token);
    }
    return result;
}

int getPlayTime(string startTime, string endTime){
    int startHour,startMinute,endHour,endMinute;
    vector<string> start = tokenizing(startTime,':');
    startHour = stoi(start[0]);
    startMinute = stoi(start[1]);
    vector<string> end = tokenizing(endTime,':');
    endHour = stoi(end[0]);
    endMinute = stoi(end[1]);
    int diffHour = endHour - startHour;
    int diffMinute = endMinute - startMinute;
    return diffHour * 60 + diffMinute;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    int maximum = 0;
    for(auto it : musicinfos){
        vector<string> info = tokenizing(it,',');
        string startTime = info[0];
        string endTime = info[1];
        string title = info[2];
        string melody = info[3];
        int melodySize = melody.size();
        int playtime = getPlayTime(startTime,endTime);
        string fullMelody ="";
        int iter = playtime;
        
        for(int i=0;i<iter;i++){
            if(melody[i%melodySize] == '#') iter++;
            fullMelody.push_back(melody[i%melodySize]);
        }
        if(melody[iter%melodySize] == '#') fullMelody.push_back('#');
        
        int mSize = m.size();
        
        while(fullMelody.find(m) != string::npos){
            int idx = fullMelody.find(m);
            if(!(m[mSize-1] != '#' && fullMelody[idx+mSize] =='#') && playtime > maximum){
                maximum = playtime;
                answer = title;
                break;
            }
            fullMelody = fullMelody.substr(idx+mSize-1);
        }
    }
    return answer;
}