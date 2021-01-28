//문자열을 빼지 말고 추가하면서 새로 가공할것
#include<bits/stdc++.h>

using namespace std;

string solution(string new_id) {
    string answer = "";
    int sz;
    int idx=0;
    for(int i=0;i<new_id.size();i++){
        if(isupper(new_id[i])){
            new_id[i] = tolower(new_id[i]);
        }
    }
    
    idx =0;
    sz=new_id.size();
    for(int i=0;i<sz;i++){
        if(new_id[idx] != '.' && new_id[idx] !='_' && new_id[idx] !='-' && !isalpha(new_id[idx]) && !isdigit(new_id[idx])){
            new_id.erase(new_id.begin()+idx);
            idx--;
        }
        idx++;
    }


    sz=new_id.size();
    bool flag=true;
   
  
    idx=0;
    for(int i=0;i<sz-1;i++){
        if(new_id[idx]=='.' && new_id[idx+1]=='.'){
            new_id.erase(new_id.begin()+idx);
            idx--;
        }
        idx++;
    }

     if(new_id[0] == '.') new_id.erase(new_id.begin());
     if(new_id[new_id.size()-1] == '.') new_id.erase(new_id.end()-1);


    if(new_id.size()==0) new_id.push_back('a');
    
    if(new_id.size()>=16) new_id.erase(15);
    
    if(new_id[new_id.size()-1] == '.') new_id.erase(new_id.end()-1);

    if(new_id.size()<=2){
        while(new_id.size()<3){
            new_id.push_back(new_id[new_id.size()-1]);
        }
    }
    return new_id;

}