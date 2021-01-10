#include<bits/stdc++.h>
using namespace std;
int solution(string s){
    int stringSize=(int)s.size();
    int minimum=stringSize;
    for(int i=1;i<=stringSize/2;i++){
        string ret;
        int idx=0;
        while(idx<stringSize){
            string ptr = s.substr(idx,i);
            idx+=i;
            int idx2=idx;
            int ptrCount=1;
            while(idx2<stringSize){
                string comparePtr=s.substr(idx2,i);
                if(ptr != comparePtr) break;
                ptrCount++;
                idx2+=i;
                idx=idx2;
            }
            
            if(ptrCount!=1) ret+=to_string(ptrCount);
            ret+=ptr;
        }
        cout << "i : "<<i <<" ret : "<<ret <<"\n";
        minimum=min((int)ret.size(),minimum);
    }
    return minimum;
}
int main(){
    string s;
    cin >> s;
    cout << solution(s);
}