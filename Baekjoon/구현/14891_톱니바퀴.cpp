#include<bits/stdc++.h>
using namespace std;
int k;
vector<char> gear[4];
vector<pair<int,int>> rotateInfo;
void doRotate(int i,int dir){
    if(dir == 1){
        rotate(gear[i].rbegin(),gear[i].rbegin()+1,gear[i].rend());
        //cout<<"dir이 1인 경우\n";
    }
    else if(dir == -1){
        rotate(gear[i].begin(),gear[i].begin()+1,gear[i].end());        
        //cout<<"dir이 -1인 경우\n";
    }
    
}
int main(){
    for(int i=0;i<4;i++){
        for(int j=0;j<8;j++){
            char c; cin >> c;
            gear[i].push_back(c);
        }
    }
    cin >> k;
    for(int i=0;i<k;i++){
        int a,b;
        cin >> a>>b;
        rotateInfo.push_back({--a,b});
    }
    
    
    for(auto it : rotateInfo){
        int rotateDir=it.second;
        int prevDir=it.second;
        vector<char> originGear=gear[it.first];
        vector<char> prevGear=gear[it.first];
        doRotate(it.first,rotateDir);

        for(int i=it.first-1; i>=0 ;i--){
            if(prevGear[6] == gear[i][2]) break;
            prevGear=gear[i];
            prevDir= -prevDir;
            doRotate(i,prevDir);
            
        }
        
        prevGear=originGear;
        prevDir=it.second;
        for(int i=it.first+1; i<4;i++){ 
            if(prevGear[2] == gear[i][6]) break;
            prevGear=gear[i];
            prevDir= -prevDir;
            doRotate(i,prevDir);
        }
    }

    int score =0;
    for(int i=0;i<4;i++){
        if(gear[i][0] == '1'){
            int addScore=0;
            if(i== 0) addScore=1;
            else if(i==1) addScore=2;
            else if(i==2) addScore=4;
            else if(i==3) addScore=8;
            score+=addScore;
        }
    }
    cout << score<<"\n";
    
}
