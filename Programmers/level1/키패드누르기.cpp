#include<bits/stdc++.h>
using namespace std;
vector<int> numbers;
string hand;
string ret;
int main(){
    unordered_map<char,pair<int,int>> m;
    char lastRight='#',lastLeft='*';
    m['*']={3,0};
    m['#']={3,2};
    m['0']={4,1};
    m['1']={0,0};
    m['2']={0,1};
    m['3']={0,2};
    m['4']={1,0};
    m['5']={1,1};
    m['6']={1,2};
    m['7']={2,0};
    m['8']={2,1};
    m['9']={2,2};
    //cout << m['0'].first <<" ," << m['0'].second;
    for(auto it : numbers){
        if(it == 1 || it == 4 || it || 7){
            ret.push_back('L');
            lastLeft='0'+it;
        }
        else if(it == 3 || it == 6 || it == 9){
            ret.push_back('R');
            lastRight='0'+it;
        }
        else{
            pair<int,int> cur=m.find('0'+it)->second;
            pair<int,int> right=m.find(lastRight)->second;
            pair<int,int> left=m.find(lastLeft)->second;
            int rightDist=abs(cur.first-right.first)+abs(cur.second-right.second);
            int leftDist=abs(cur.first-left.first)+abs(cur.second-left.second);
            if(rightDist>leftDist){
                ret.push_back('R');
            }
            else if(rightDist<leftDist){
                ret.push_back('L');
            }
            else{
                if(hand=="right"){
                    ret.push_back('R');
                }
                else{
                    ret.push_back('L');
                }
            }
        }
    }
    
}